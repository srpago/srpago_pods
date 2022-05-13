//
//  CurrencyTextField.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 28/12/21.
//

import Foundation
import SwiftUI

class CurrencyUITextField: UITextField {
    
    @Binding var value: Double
    @Binding private var amountSale: String
    
    init(value: Binding<Double>,
         amountSale: Binding<String>) {
        self._value = value
        self._amountSale = amountSale
        super.init(frame: .zero)
        setupViews()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func willMove(toSuperview newSuperview: UIView?) {
        addTarget(self, action: #selector(editingChanged), for: .editingChanged)
        keyboardType = .decimalPad
    }
    
    func clean() {
        DispatchQueue.main.async {
            self.value = 0
            self.amountSale = ""
            self.text = ""
        }
    }
    
    private func setupViews() {
        tintColor = .clear
        delegate = self
        placeholder = "$0.00"
    }
    
    @objc private func editingChanged() {
        if let amountString = text?
            .replacingOccurrences(of: "$", with: "")
            .currencyFormat() {
            text = "$\(amountString)"
            let amountValue = doubleValue(
                amountString.replacingOccurrences(of: ",", with: "")
            )
            value = amountValue
            amountSale = "\(amountValue)"
        }
    }
    
    private func doubleValue(_ value: String) -> Double {
        return Double(value) ?? 0
    }
}

extension CurrencyUITextField: UITextFieldDelegate {
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange,
                   replacementString string: String) -> Bool {
        let maxLength = 13
        let currentString: NSString = (textField.text ?? "") as NSString
        let newString: NSString =
        currentString.replacingCharacters(in: range, with: string) as NSString
        return newString.length <= maxLength
    }
}

struct CurrencyTextField: UIViewRepresentable {
    
    let currencyField: CurrencyUITextField
    
    init(value: Binding<Double>,
         amountSale: Binding<String>) {
        currencyField = CurrencyUITextField(value: value,
                                            amountSale: amountSale)
    }
    
    func makeUIView(context: Context) -> CurrencyUITextField {
        return currencyField
    }
    
    func updateUIView(_ uiView: CurrencyUITextField, context: Context) {
        if uiView.text != "" && currencyField.value == 0.0 {
            uiView.clean()
        }
    }
}
