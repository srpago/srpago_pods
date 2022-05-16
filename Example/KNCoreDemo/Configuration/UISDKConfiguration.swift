//
//  UISDKConfiguration.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 28/02/22.
//

import KNCore
import UIKit

struct UISDKConfiguration {
    
    static func signature() -> KNSignatureViewData {
        
        let acceptButton = SignatureButtonViewData(
            icon: nil, font: UIFont.systemFont(ofSize: 16), backgroundColor: .black,
            textColor: .white, borderWidth: 0, disableBackground: .gray, disableText: .white, corner: .square
        )
        let clearButton = SignatureButtonViewData(
            icon: nil, font: UIFont.systemFont(ofSize: 16), backgroundColor: .clear,
            textColor: .black, borderWidth: 0, disableBackground: .clear, disableText: .gray, corner: .square
        )
        let titleLabel = SignatureLabelViewData(
            textColor: .darkGray, font: UIFont.systemFont(ofSize: 16), alignment: .left
        )
        let signHereLabel = SignatureLabelViewData(
            textColor: .black, font: UIFont.systemFont(ofSize: 20), alignment: .center
        )
        let tipLabel = SignatureLabelViewData(
            textColor: .white, font: UIFont.systemFont(ofSize: 16), alignment: .center
        )
        let legendLabel = SignatureLabelViewData(
            textColor: .white, font: UIFont.systemFont(ofSize: 16), alignment: .center
        )
        
        return KNSignatureViewData(
            orientation: .landscapeLeft,
            waterMark: nil,
            headerHeight: 80,
            headerColor: .darkGray,
            bottomColor: .clear,
            clearButton: clearButton,
            acceptButton: acceptButton,
            totalAmount: titleLabel,
            signatureHere: signHereLabel,
            signatureDigital: legendLabel,
            tipAmount: tipLabel
        )
    }
}

