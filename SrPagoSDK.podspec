Pod::Spec.new do |sdk|

  sdk.name         = "SrPagoSDK"
  sdk.version      = "2.5.0"
  sdk.summary      = "Payments SDK for Konfio and Sr.Pago"
  sdk.description  = <<-DESC
  Payment SDK with support for SrPago Readers:
  - Pin Pad mini (WisePad Q),
  - Pin Pad (PAX_D180),
  This SDK let you:
  - Link readers
  - Make transactions with fisical cards and readers using EMV
  - See previous transactions for your user or company
  - Send tickets for your transactions
  - See transaction's history
  - Made refound for previous transactions
                   DESC

  sdk.homepage     = "https://srpago.com"

  sdk.license      = { :type => "MIT", :text => "© 2022 Konfio" }

  sdk.authors      = {
    'Luis Fernando Bustos Ramírez' => 'luis.bustos@konfio.mx',
    'Jorge Mejía Mulhia' => 'jorge.mejia@konfio.mx',
    'Luis Genaro Arvizu Vega' => 'luis.arvizu@konfio.mx',
    'Martín González Escamilla' => 'martin.gonzalez@konfio.mx'
   }

  sdk.ios.deployment_target = '11.0'

  sdk.source       = { :git => "https://github.com/srpago/srpago_pods.git", :tag => sdk.version.to_s }

  sdk.vendored_frameworks = 'KNCore.xcframework', 'KNPayment.xcframework', 'KNBluetoothModule.xcframework', 'KNPaymentModule.xcframework', 'KNPrinterModule.xcframework', 'KNAnalyticsPaymentModule.xcframework', 'KNBusinessModule.xcframework'
  sdk.user_target_xcconfig = {
    'SWIFT_INCLUDE_PATHS' => '"${PODS_XCFRAMEWORKS_BUILD_DIR}/'+"#{sdk.name}"+'"'
}

end
