//
//  TransactionTipView.swift
//  KNCoreDemo
//
//  Created by Jorge Mulhia on 29/12/21.
//

import SwiftUI

struct TransactionTipView: View {
    
    @StateObject var viewModel: TransactionWorkFlowViewModel
    @State private var tip: Double = 0
    @State private var tipAmount: String = "0"
    
    var body: some View {
        ZStack {
            Color.gray.brightness(0.8)
            VStack {
                Text("¿Deseas agregar propina?")
                    .frame(width: 250, height: 25, alignment: .center)
                    .font(.system(size: 18))
                    .lineLimit(nil)
                    .padding(20)
                    .padding(.bottom, 0)
                Text("Por favor ingresa una propina inferior al 30%")
                    .frame(width: 250, height: 40, alignment: .center)
                    .font(.system(size: 14))
                    .lineLimit(nil)
                    .padding(10)
                    .padding(.vertical, 0)
                CurrencyTextField(value: $tip,
                                  amountSale: $tipAmount)
                    .keyboardType(.decimalPad)
                    .frame(width: 260, height: 30, alignment: .center)
                    .padding(10)
                    .padding(.vertical, 4)
                Button(action: {
                    if tip > 0 {
                        viewModel.add(tip: "\(tip)")
                    } else {
                        viewModel.add(tip: "0")
                    }
                    viewModel.showsTipAlert = false
                }) {
                    Text("Aceptar")
                }
                .padding(10)
                .padding(.top, 0)
            }
        }
        .frame(width: 300, height: 260,alignment: .center)
        .cornerRadius(20).shadow(radius: 20)
    }
}
