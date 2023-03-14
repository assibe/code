//
//  insertApp.swift
//  insert
//
//  Created by 周仁玺 on 2023/3/13.
//

import SwiftUI

@main
struct insertApp: App {
    var body: some Scene {
        DocumentGroup(newDocument: insertDocument()) { file in
            ContentView(document: file.$document)
        }
    }
}
