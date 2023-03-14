//
//  ContentView.swift
//  insert
//
//  Created by 周仁玺 on 2023/3/13.
//

import SwiftUI

struct ContentView: View {
    @Binding var document: insertDocument

    var body: some View {
        TextEditor(text: $document.text)
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView(document: .constant(insertDocument()))
    }
}
