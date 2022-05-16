//
//  OperationCellView.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 12/11/21.
//

import SwiftUI

struct OperationCellView: View {
    
    var operation: Operation
    
    var body: some View {
        HStack {
            VStack(alignment: .leading) {
                Text(operation.reference)
                    .fontWeight(.semibold)
                    .foregroundColor(.black)
                Spacer()
                Text(operation.date)
                    .foregroundColor(.gray)
            }
            Spacer()
            VStack(alignment: .leading) {
                Text("$\(operation.ammount)")
                    .foregroundColor(Color(operation.color))
                    .frame(width: 80, alignment: .trailing)
                if (operation.canceled) {
                    Spacer()
                    Text("Cancelada")
                        .foregroundColor(.gray)
                }
            }
        }
        .padding(8)
    }
}

struct OperationCellView_Previews: PreviewProvider {
    static var previews: some View {
        Group {
            let operation = Operation(
                id: "MzI2NDA4Mzc=",
                reference: "Abono a tarjeta: 376662XXXXXX3009",
                ammount: "605.52",
                date: "2021-11-08T19:17:07-06:00",
                canceled: true,
                color: UIColor(named: "PurpleKonfio") ?? .black
            )
            OperationCellView(operation: operation)
                .previewLayout(.sizeThatFits)
        }
    }
}
