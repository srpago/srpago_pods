//
//  ContentView.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 12/10/21.
//

import SwiftUI

struct HeaderView: View {
    
    @Binding var deviceName: String
    @Binding var userName: String
    
    var body: some View {
        VStack(alignment: .leading, spacing: 10) {
            Text("KNPaymentCore Demo")
                .font(.system(size: 27))
                .foregroundColor(.white)
                .padding(.horizontal)
                .padding(.top, 70)
            HStack {
                Text("Hi! \n\(userName)")
                    .font(.subheadline)
                    .foregroundColor(.white)
                Spacer()
                NavigationLink(destination: ListDevicesUIView()) {
                    Image("\(deviceName)", bundle: nil)
                        .resizable()
                        .scaledToFit()
                        .frame(width: 40.0, height: 40.0)
                        .padding(10)
                        .background(Color.white)
                        .cornerRadius(40)
                }
            }
            .padding(.horizontal)
            Spacer()
        }
        .frame(maxWidth: .infinity)
        .background(Color.init("PurpleKonfio"))
        .edgesIgnoringSafeArea(.all)
    }
}

struct MenuButton: View {
    
    var text: String
    
    var body: some View {
        Text(text)
            .frame(width: 200, height: 35)
            .padding()
            .background(Color.init("PurpleKonfio"))
            .foregroundColor(.white)
            .cornerRadius(10)
    }
}

struct ContainerView: View {
    
    var body: some View {
        VStack(spacing: 20) {
            NavigationLink(destination: ListDevicesUIView()) {
                MenuButton(text: "Buscar lector")
            }
            NavigationLink(destination: PaymentView()) {
                MenuButton(text: "Hacer un cobro")
            }
            NavigationLink(destination: OperationsView()) {
                MenuButton(text: "Listado de transacciones")
            }
            NavigationLink(destination: OTAUpdateView()) {
                MenuButton(text: "Actualización OTA")
            }
            .padding(.bottom, 30)
        }
        .frame(maxWidth: .infinity)
        .padding()
        .background(Color.white)
        .compositingGroup()
        .cornerRadius(8)
        .edgesIgnoringSafeArea(.all)
    }
}

struct ContentView: View {
    
    @StateObject var contentViewModel: ContentViewModel = ContentViewModel()
    @State var userName: String = ""
    @State var showLogin = false
    
    var body: some View {
        NavigationView {
            ZStack {
                VStack {
                    HeaderView(deviceName: $contentViewModel.deviceName,
                               userName: $userName)
                        .frame(height: 380)
                    Spacer()
                }
                VStack {
                    ContainerView()
                        .padding(.horizontal)
                        .padding(.top, 200)
                        .shadow(color: Color.black.opacity(0.15), radius: 5, x: 0, y: -5)
                    Spacer()
                }
                KNCoreDemoMenu(userName: $userName,
                               showLogin: $showLogin,
                               currentScreen: "Main")
                    .frame(maxWidth: .infinity, maxHeight: .infinity)
            }
            .navigationBarTitleDisplayMode(.inline)
            .navigationBarTitle("", displayMode: .inline)
            .navigationBarHidden(true)
            .onAppear {
                userName = getUserName()
                if !userName.isEmpty {
                    loginAgain()
                } else {
                    showLogin = true
                }
                contentViewModel.getReaderInfo()
                contentViewModel.searchPreviousReader()
            }
        }
        .fullScreenCover(isPresented: $showLogin, content: {
            KNCoreLoginView(userName: $userName,
                            showLogin: $showLogin)
        })
    }
    
    func getUserName() -> String {
        return contentViewModel.getUserName()
    }
    
    func loginAgain() {
        contentViewModel.loginAgain()
    }
    
    func login(){
        contentViewModel.login { success in
            if success {
                userName = getUserName()
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
