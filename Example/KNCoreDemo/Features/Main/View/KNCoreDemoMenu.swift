//
//  KNCoreDemoMenu.swift
//  demo
//
//  Created by Jorge Mulhia on 05/12/21.
//

import SwiftUI
import KNPayment
import KNCore

struct VisualEffectView: UIViewRepresentable {
    var effect: UIVisualEffect?
    func makeUIView(context: UIViewRepresentableContext<Self>) -> UIVisualEffectView { UIVisualEffectView() }
    func updateUIView(_ uiView: UIVisualEffectView, context: UIViewRepresentableContext<Self>) { uiView.effect = effect }
}

struct MenuItem: View {
    
    var environment: KNEnvironmentType
    var function: (KNEnvironmentType) -> Void
    let config = KNConfigurator.getEnvironment()
    
    var body: some View {
        Button {
            function(environment)
        } label: {
            Text(environment.rawValue)
                .font(.system(size: 14))
                .padding()
                .background(
                    config == environment ? Color.init("GreenKonfio") : Color.init("PurpleKonfio")
                )
                .foregroundColor(.white)
                .clipShape(Capsule())
        }
        .padding(.trailing)
    }
}

struct KNCoreDemoMenu: View {
    
    @Binding var userName: String
    @Binding var showLogin: Bool
    @State var currentScreen: String = ""
    @State private var animateMenu = false
    @State private var showMenuItem1 = false
    @State private var showMenuItem2 = false
    
    var body: some View {
        let currentColor = currentScreen == "Login" ? Color.white : Color.init("PurpleKonfio")
        ZStack {
            if animateMenu {
                VisualEffectView(effect: UIBlurEffect(style: .light))
                    .gesture(
                        TapGesture().onEnded { _ in showMenu() }
                    )
            }
            HStack(alignment: .bottom) {
                VStack(alignment: .leading) {
                    Text(PaymentManager.shared.payment.getPaymentsCoreVersion())
                        .font(.system(size: 14))
                        .foregroundColor(currentColor)
                    let config = KNConfigurator.getEnvironment()
                    Text("Environment: \(config.rawValue)")
                        .font(.system(size: 14))
                        .foregroundColor(currentColor)
                }
                .padding()
                Spacer()
                VStack(alignment: .trailing) {
                    Spacer()
                    if showMenuItem1 {
                        MenuItem(environment: .sandbox,
                                 function: { environment in
                            changeEnvironment(environment)
                        })
                    }
                    if showMenuItem2 {
                        MenuItem(environment: .production,
                                 function: { environment in
                            changeEnvironment(environment)
                        })
                    }
                    Button(action: {
                        showMenu()
                    }) {
                        Image(systemName: "gearshape.circle.fill")
                            .resizable()
                            .frame(width: 40, height: 40)
                            .foregroundColor(currentColor)
                            .shadow(color: .gray, radius: 0.2, x: 1, y: 1)
                            .rotationEffect(
                                Angle(degrees: animateMenu ? -45 : 0)
                            )
                    }
                    .padding()
                }
            }
            .padding(.bottom, 20)
        }
        .edgesIgnoringSafeArea(.all)
    }
    
    func showMenu() {
        withAnimation {
            animateMenu.toggle()
        }
        animate(0.2) { showMenuItem2.toggle() }
        animate(0.4) { showMenuItem1.toggle() }
    }
    
    func animate(_ delay: CGFloat, completion: @escaping () -> Void) {
        DispatchQueue.main.asyncAfter(deadline: .now() + delay, execute: {
            withAnimation {
                completion()
            }
        })
    }
    
    func changeEnvironment(_ environment: KNEnvironmentType) {
        showMenu()
        let currentEnvironment = LocalPersistanceCatalog.currentEnvironment.rawValue
        let currEnvironment: String = KNPersistanceModel().getValue(currentEnvironment) ?? ""
        if currEnvironment != environment.rawValue {
            KNConfigurator.setEnvironment(environment)
            let config = KNConfigurator(environment: environment, appkey: environment.getKeys().0, appSecret: environment.getKeys().1)
            PaymentManager.shared.payment.config(config)
            
            userName = ""
            showLogin = true
            KNPersistanceModel().save("", key: LocalPersistanceCatalog.currentUser.rawValue)
            KNPersistanceModel().save("", key: LocalPersistanceCatalog.currentUserPassword.rawValue)
        }
    }
}

