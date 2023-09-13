#include "httplib.hpp"
#include "data.hpp"

#define WWWROOT "./www"
#define VIDEO_ROOT "/video/"
#define IMAGE_ROOT "/image/"

namespace aod
{

	class TableVideo *tb_video = NULL;

	class Server
	{

	private:
		int _port;
		httplib::Server _srv;

	public:
		static void Insert(const httplib::Request &req, const httplib::Response &rsp)
		{

			if (req.has_file("name") == false || req.has_file("info") == false || req.has_file("vido") == false || req.has_file("image") == false)
			{
				rsp.status = 400;
				rsp.body = R"({"result":false, "reason":"上传的数据信息错误"})";
				rsp.set_header("Content-Type", "application/json");
				return;
			}

			httplib::MultipartFormData name = req.get_file_value("name");
			// 名称
			httplib::MultipartFormData info = req.get_file_value("info");
			// 简介
			httplib::MultipartFormData video = req.get_file_value("video");
			// 视频
			httplib::MultipartFormData image = req.get_file_value("image");
			// 图片

			std::string video_name = name.content;
			std::string video_info = info.content;

			std::string root = WWWROOT;
			std::string video_path = root + VIDEO_ROOT + VIDEO_ROOT + video.filename;
			std::string image_path = root + IMAGE_ROOT + IMAGE_ROOT + image.filename;

			if (FileUtil(video_path).SetContent(video.content) == false)
			{
				rsp.status = 500;
				rsp.body = R"({"result":false, "reason":"视频文件不存在"})"; // 输出错误信息到服务端
				rsp.set_header("Content_Type", "application/json");
				return ;
			} // 写入视频文件

			if (FileUtil(image_path).SetContent(image.content) == false)
			{
				req.status = 500;
				req.body = R"({"result":false, "reason":"图片数据失去"})"; // 输出错误信息到服务端
				req.set_header("Content_Type", "application/json");
				return ;
			} // 写入图片文件

			Json::Value video_json;
			video_json["name"] = video_name;
			video_json["info"] = video_info;
			video_json["video"] = VIDEO_ROOT + video_name + video.filename;
			video_json["image"] = IMAGE_ROOT + video_name + image.filename;

			if (tb_video->Insert(video_json) == false)
			{
				rsp.status = 500;
				rsp.body = R"({"result":false, "reason":"数据库插入失败"})"; // 输出错误信息到服务端
				rsp.set_header("Content_Type", "application/json");
				return ;
			}
			return ;
		} // 插入视频等信息

		static void Delete(const httplib::Request &req, const httplib::Response &rsp)
		{
			int video_id = std::stoi(req.matches[1]);
			// 获取删除视频的id

			Json::Value video;
			if (tb_video->Delete(video_id) == false)
			{
				rsp.status = 500;
				rsp.body = R"({"result":false, "reason":"删除数据库信息失败"})";
				rsp.set_header("Content-Type", "application/json");
				return ;
			} // 寻找视频信息

			std::string root = WWWROOT;
			std::string video_path = WWWROOT + video["video"].asString();
			std::string image_path = WWWROOT + video["image"].asString();
			remove(video_path.c_str());
			remove(image_path.c_str());
			// 删除文件

			if (tb_video->Delete(video_id) == false)
			{
				rsp.status = 500;
				rsp.body = R"({"result":false, "reason":"删除数据库信息失败"})";
				rsp.set_header("Content-Type", "application/Json");
				return ;
			}

			return;
		} // 删除数据信息

		static void Update(const httplib::Request &req, const httplib::Response &rsp)
		{
			int video_id = std::stoi(req.matches[1]);

			Json::Value video;
			if (JsonUtil::UnSerialize(req.body, &video) == false)
			{
				rsp.status(400);
				rsp.body = R"({"result":false,"reason":"视频格式解析失败信息失败"})";
				rsp.set_header("Content-Type", "application/Json");
				return ;
			} // 反序列化

			if (tb_video->Update(video_id, video) == false)
			{
				rsp.status = 400;
				rsp.body = R"({"result":false,"reason":"数据库修改数据失败失败"})";
				rsp.set_header("Content-Type", "application/json");
				return ;
			} // 修改数据库信息
		}

		static void SelectOne(const httplib::Request &req, const httplib::Response &rsp)
		{
			int vide_id = std::stoi(req.matches[1]);
			// 匹配视频id

			Json::Value video;
			if (tb_video->SelectOne(vide_id, &video) == false)
			{
				rsp.status = 400;
				rsp.body = R"({"result":false,"reason":"视频不存在"})";
				rsp.set_header("Content-Type", "application/json");
				return ;
			} // 寻找视频位置

			JsonUtil::Serialize(video,&rsp.body);
			rsp.status = 200;
			rsp.set_header("Content-Type", "application/json");
			return ;
		}

		static void SelectAll(const httplib::Request &req, httplib::Response &rsp)
		{

			bool select_flag = true; // 默认所有查询
			std::string search_key;
			if (req.has_param("search") == true)
			{
				select_flag = false; // 模糊匹配
				search_key = req.get_param_value("search");
			}

			Json::Value videos;
			if (select_flag == true)
			{
				if (tb_video->SelectAll(&videos) == false)
				{
					rsp.status = 500;
					rsp.body = R"({"result":false, "reason":"查询数据库所有视频信息失败"})";
					rsp.set_header("Content-Type", "application/json");
					return ;
				}
			}
			else
			{
				if (tb_video->SelectLike(search_key, &videos) == false)
				{
					rsp.status = 500;
					rsp.body = R"({"result":false, "reason":"查询数据库匹配视频信息失败"})";
					rsp.set_header("Content-Type", "application/json");
					return ;
				}
			}
			JsonUtil::Serialize(videos, &rsp.body);
			rsp.set_header("Content-Type", "application/json");
			return ;
		}

		// 不同的请求对于数据库的操作

	public:
		Server(int port) : _port(port) {}

		bool RunModule()
		{

			tb_video = new TableVideo();
			FileUtil(WWWROOT).CreateDirectory();

			std::string root = WWWROOT;

			std::string video_real_path = root + VIDEO_ROOT;
			FileUtil(video_real_path).CreateDirectory();

			std::string imge_real_path = root + IMAGE_ROOT;
			FileUtil(imge_real_path).CreateDirectory();

			// 创建目录文件

			_srv.set_mount_point("/",WWWROOT);
			// 设置静态服务器

			_srv.Post("/video", Insert);
			_srv.Delete("/video/(\\d+)", Delete);
			_srv.Put("/video(\\d+)", Update);
			_srv.Get("/video/(\\)", SelectOne);
			_srv.Get("/video", SelectAll);
			// 不同方法的请求信息,动态的服务器设计

			_srv.listen("0.0.0.0", _port);
			return true;
		};
	};
}

