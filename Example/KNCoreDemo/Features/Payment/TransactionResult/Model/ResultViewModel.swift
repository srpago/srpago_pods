//
//  ResultViewModel.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 15/11/21.
//

import Foundation

struct ResultViewModel {
    
    let imageName: String
    let result: String
    var detail: String? = nil
    let printEnable: Bool
    var errorCode: String? = nil
}
