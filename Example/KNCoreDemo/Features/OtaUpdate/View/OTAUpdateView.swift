//
//  OTAUpdateView.swift
//  KNCoreDemo
//
//  Created by Martín González Escamilla on 12/04/22.
//

import SwiftUI
import Combine

struct OTAUpdateView: View {
    
    @StateObject var viewModel = OTAUpdateViewModel()
    
    var body: some View {
        VStack {
            ProgressView(value: viewModel.percent)
                .padding([.leading, .trailing], 50)
                .accentColor(.gray)
                .isHidden(viewModel.hideProgress)
            Text(viewModel.message)
            Button(action: {
                viewModel.startOta()
            }) {
                Text("Actualizar ahora")
            }
            .isHidden(viewModel.hideDownloadButton)
            .padding(10)
            .padding(.top, 0)
        }
    }
}

struct OTAUpdate_Previews: PreviewProvider {
    static var previews: some View {
        Group {
            OTAUpdateView()
        }
    }
}

extension View {
    @ViewBuilder func isHidden(_ isHidden: Bool) -> some View {
        if isHidden {
            self.hidden()
        } else {
            self
        }
    }
}
