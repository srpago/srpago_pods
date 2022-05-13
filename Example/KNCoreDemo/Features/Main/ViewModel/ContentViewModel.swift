//
//  ContentViewModel.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 11/11/21.
//

import Foundation
import KNPayment
import KNCore

class ContentViewModel: ObservableObject {
    
    @Published var device: KNBluetoothReader?
    @Published var deviceName: String = ""
    @Published var presentLogin = false
    
    func searchPreviousReader() {
        PaymentManager.shared.payment.tryReconnect()
    }
    
    func getReaderInfo() {
        PaymentManager.shared.payment.getReader { [weak self] readerInfo in
            switch readerInfo.readerTypeConnection{
            case .paxD180:
                self?.deviceName = "D180"
            case .pinPadMini:
                self?.deviceName = "BBPOS"
            }
            debugPrint(readerInfo)
        } error: { [weak self] errorDetail in
            debugPrint(errorDetail)
            self?.deviceName = "NoReader"
        }
    }
    
    func getUserName() -> String {
        let currentUser = LocalPersistanceCatalog.currentUser.rawValue
        let savedUser: String? = KNPersistanceModel().getValue(currentUser)
        return savedUser ?? ""
    }
    
    func login(userName: String = "", password: String = "", completion: @escaping(Bool) -> Void) {
        let environment = KNConfigurator.getEnvironment()
        let credentials =  environment.getCredentials()
        let loginUserName = userName != "" ? userName : credentials.user
        let loginPassword = password != "" ? password : credentials.password
        PaymentManager.shared.payment.login(user: loginUserName, password: loginPassword) { response in
            switch response {
            case .success(let success):
                completion(success)
            case .failure(_):
                completion(false)
            }
        }
    }
    
    func loginAgain() {
        let currentUser = LocalPersistanceCatalog.currentUser.rawValue
        let user: String = KNPersistanceModel().getValue(currentUser) ?? ""
        
        let currentPassword = LocalPersistanceCatalog.currentUserPassword.rawValue
        let password: String = KNPersistanceModel().getValue(currentPassword) ?? ""
        
        PaymentManager.shared.payment.login(user: user, password: password) { _ in
            debugPrint("Login again: user: \(user) password: \(password)")
            let environment = KNConfigurator.getEnvironment()
            let config = KNConfigurator(environment: environment, appkey: environment.getKeys().0, appSecret: environment.getKeys().1)
            PaymentManager.shared.payment.config(config)
        }
    }
}
