//
//  ListDevicesUIView.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 14/10/21.
//

import SwiftUI

struct ListDevicesUIView: View {
    
    @Environment(\.presentationMode) var presentationMode
    @StateObject var listViewModel: ListDevicesViewModel = ListDevicesViewModel()
    
    var body: some View {
        ZStack {
            VStack(content: {
                Text("Selecciona tu lector")
                    .font(.title)
                    .foregroundColor(.black)
                Spacer()
                    .frame(height: 20)
                Text("Estatus: \(listViewModel.status)")
                    .frame(maxWidth: .infinity, alignment: .leading)
                    .multilineTextAlignment(.leading)
                    .padding(10)
                Spacer()
                    .frame(height: 10)
                HStack {
                    Text("Lectores encontrados:")
                        .font(.caption)
                        .multilineTextAlignment(.leading)
                        .padding(5)
                        .padding(.leading, 10)
                    if listViewModel.readerLinked != "" {
                        Spacer()
                        Text("Lector conectado: \(listViewModel.readerLinked)")
                            .font(.caption)
                            .multilineTextAlignment(.leading)
                            .padding(5)
                            .padding(.trailing, 10)
                    } else {
                        Spacer()
                    }
                }
                Spacer()
                    .frame(height: 20)
                List {
                    ForEach(listViewModel.devices) { device in
                        Button(action: {
                            listViewModel.connectWith(reader: device)
                        }, label: {
                            HStack {
                                Image("\(device.readerType.image)", bundle: nil)
                                    .resizable()
                                    .scaledToFit()
                                    .frame(width: 40.0, height: 40.0)
                                    .padding(10)
                                    .background(Color.white)
                                    .cornerRadius(40)
                                VStack {
                                    Text("\(device.device.name) (\(device.readerType.bluetoothDescription))")
                                        .foregroundColor(.black)
                                        .frame(maxWidth: .infinity, alignment: .leading)
                                        .multilineTextAlignment(.leading)
                                    Text(device.device.identifier)
                                        .font(.footnote)
                                        .foregroundColor(.gray)
                                        .frame(maxWidth: .infinity, alignment: .leading)
                                        .multilineTextAlignment(.leading)
                                }
                            }
                        })
                    }
                }
                Spacer()
            })
            ZStack {
                VisualEffectView(effect: UIBlurEffect(style: .extraLight))
                VStack {
                    Text(listViewModel.status)
                        .frame(maxWidth: .infinity, alignment: .center)
                        .multilineTextAlignment(.center)
                        .padding(20)
                    Arcs(isAnimating: $listViewModel.isLoading,
                         count: 5,
                         width: 8,
                         spacing: 5
                    )
                        .frame(width: 150, height: 150, alignment: .center)
                }
            }.hidden(!listViewModel.isLoading)
        }
        .onAppear {
            listViewModel.startScan(self)
            listViewModel.getReaderInfo()
        }
        .onDisappear {
            listViewModel.stopScan()
        }
        .alert(item: $listViewModel.alert) { result in
            if let secondMessage = result.secondaryButtonMessage {
                return Alert(
                    title: Text(result.title),
                    message: Text(result.body),
                    primaryButton: .default(
                        Text(result.primaryButtonMessage),
                        action: result.primaryAction
                    ),
                    secondaryButton: .default(
                        Text(secondMessage)
                    )
                )
            }
            return Alert(
                title: Text(result.title),
                message: Text(result.body),
                dismissButton: .default(
                    Text(result.primaryButtonMessage),
                    action: result.primaryAction
                )
            )
        }
    }
}

struct ListDevicesUIView_Previews: PreviewProvider {
    static var previews: some View {
        ListDevicesUIView()
    }
}
