//
//  KNEnvironmentType+Extension.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 20/01/22.
//

import KNCore

extension KNEnvironmentType {
    
    func getCredentials() -> (user:String, password:String) {
        return (user: "", password: "")
    }
    
    func getKeys() -> (String, String) {
        switch self {
        case .sandbox:
            return ("sk_dev_5d76bc7b13a7246503b508b134ca88b96", "Vc25yfZ26yMH")
        default:
            return("", "")
        }
    }
}
