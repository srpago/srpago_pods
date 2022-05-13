//
//  KNPaymentState+Extension.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 11/01/22.
//

import Foundation
import KNCore

extension KNPaymentState {
    
    public var message: String {
        switch self {
        case .startPayment:
            return "Espere un momento"
        case .typeTip:
            return "Ingresa la propina"
        case .retypeTip:
            return "Propina incorrecta, ingresala nuevamente"
        case .insertCard:
            return "Inserta, desliza o acerca la tarjeta"
        case .cardDetected:
            return "Espere un momento"
        case .typePin:
            return "Ingresa tu PIN en el lector"
        case .retypePin:
            return  "PIN incorrecto, ingresalo nuevamente"
        case .requestOnlineProcess:
            return "Procesando pago"
        case .selectMonthWithoutInterest:
            return "Selecciona los meses sin intereses"
        case .typeSignature:
            return "Ingresa tu firma electronica"
        case .retypeSignature:
            return "Hubo un problema con la firma, ingresala nuevamente"
        case .paymentSuccess:
            return "Pago exitoso"
        case .paymentError:
            return "Error en el pago"
        case .paymentReversal:
            return "Evaluando reversos automaticos"
        case .locationPermissionUnauthorized:
            return "Permisos de localización no autorizados"
        case .typePan:
            return "Ingresa los 4 ultimos digitos de tu tarjeta"
        case .retypePan:
            return "PAN incorrecto, ingresa los 4 ultimos digitos de tu tarjeta nuevamente"
        case .tapOrInsertCard:
            return "Inserta, desliza o acerca la tarjeta"
        }
    }
}
