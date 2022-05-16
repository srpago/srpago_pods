//
//  KNCoreLoginView.swift
//  KNCoreDemo
//
//  Created by Jorge Mulhia on 05/12/21.
//

import SwiftUI

struct KNCoreLoginView: View {
    
    @Environment(\.presentationMode) var presentationMode
    @Binding var userName: String
    @Binding var showLogin: Bool
    @State private var password: String = ""
    @State private var showError = false
    @State private var errorMessage = ""
    
    var body: some View {
        ZStack {
            VStack {
                Text("KNPaymentCore Demo")
                    .font(.system(size: 27))
                    .foregroundColor(.white)
                    .padding(.horizontal)
                    .padding(.top, 100)
                TextField("", text: $userName)
                    .placeholder(userName.isEmpty) {
                        Text("Name").foregroundColor(.white)
                    }
                    .underlineTextField()
                    .keyboardType(.emailAddress)
                    .autocapitalization(.none)
                    .disableAutocorrection(true)
                    .padding(.horizontal, 30)
                    .padding(.bottom, 10)
                    .ignoresSafeArea(.keyboard, edges: .bottom)
                SecureField("", text: $password)
                    .placeholder(password.isEmpty) {
                        Text("Password").foregroundColor(.white)
                    }
                    .underlineTextField()
                    .autocapitalization(.none)
                    .disableAutocorrection(true)
                    .padding(.horizontal, 30)
                    .padding(.bottom, 30)
                    .ignoresSafeArea(.keyboard, edges: .bottom)
                Button(action: {
                    ContentViewModel().login(userName: userName, password: password) { status in
                        if status {
                            userName = userName
                            presentationMode.wrappedValue.dismiss()
                        } else {
                            showError = true
                        }
                    }
                }) {
                    Text("Login")
                        .frame(width: 200, height: 35)
                        .padding()
                        .background(Color.init("PurpleKonfio"))
                        .border(.white, width: 1)
                        .foregroundColor(.white)
                }
                Spacer()
                .alert(isPresented: $showError, content: {
                    Alert(title: Text(errorMessage), message: Text("Please try again"), dismissButton: .default(Text("Close")))
                })
            }
            KNCoreDemoMenu(userName: $userName,
                           showLogin: $showLogin,
                           currentScreen: "Login")
                .frame(maxWidth: .infinity, maxHeight: .infinity)
        }
        .onTapGesture {
            endEditing()
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .background(Color.init("PurpleKonfio"))
        .edgesIgnoringSafeArea(.all)
    }
}

extension View {
    func placeholder<Content: View>(_ show: Bool, @ViewBuilder placeholder: () -> Content) -> some View {
        ZStack(alignment: .leading) {
            placeholder().opacity(show ? 1 : 0)
            self
        }
    }
    
    func underlineTextField() -> some View {
        self
            .padding(.vertical, 15)
            .overlay(
                Rectangle()
                    .frame(height: 1)
                    .padding(.top, 50))
            .foregroundColor(.white)
            .padding(15)
    }
    
    func endEditing() {
        let keyWindow = UIApplication.shared.connectedScenes
            .filter({$0.activationState == .foregroundActive})
            .map({$0 as? UIWindowScene})
            .compactMap({$0})
            .first?.windows
            .filter({$0.isKeyWindow}).first
        keyWindow?.endEditing(true)
    }
}
