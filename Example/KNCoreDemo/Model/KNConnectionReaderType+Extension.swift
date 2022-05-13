//
//  KNConnectionReaderType+Extension.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 06/12/21.
//

import Foundation
import KNCore

extension KNConnectionReaderType {
    
    public var image: String {
        switch self {
        case .paxD180:
            return "D180"
        case .pinPadMini:
            return "BBPOS"
        }
    }
    
}
