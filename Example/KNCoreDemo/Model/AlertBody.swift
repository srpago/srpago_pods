//
//  AlertBody.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 15/11/21.
//

import Foundation

struct AlertBody: Identifiable {
    
    let id: ObjectIdentifier
    let title: String
    let body: String
    let primaryButtonMessage: String
    var primaryAction: (() -> Void)? = {}
    var secondaryButtonMessage: String? = nil
    var secondaryAction: (() -> Void)? = {}
}
