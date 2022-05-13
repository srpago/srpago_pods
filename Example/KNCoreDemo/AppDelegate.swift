//
//  AppDelegate.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 12/10/21.
//

import UIKit
import KNPayment
import KNCore

@main
class AppDelegate: UIResponder, UIApplicationDelegate {

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        let environment: KNEnvironmentType = KNConfigurator.getEnvironment()
        let config = KNConfigurator(environment: environment, appkey: environment.getKeys().0, appSecret: environment.getKeys().1)
        PaymentManager.shared.payment.config(config)
        PaymentManager.shared.payment.configSignatureUI(UISDKConfiguration.signature())
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication,
                     configurationForConnecting connectingSceneSession: UISceneSession,
                     options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }
}
