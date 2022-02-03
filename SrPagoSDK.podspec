Pod::Spec.new do |sdk|

  sdk.name         = "SrPagoSDK"
  sdk.version      = "2.0.0"
  sdk.summary      = "SDK de Sr.pago"
  sdk.description  = <<-DESC
    SDK de Señor pago para iOS
                   DESC

  sdk.homepage     = "https://srpago.com"

  sdk.license      = { :type => "MIT", :text => "© 2022 SrPago" }

  sdk.authors      = {
    'Luis Fernando Bustos Ramírez' => 'luis.bustos@konfio.mx',
    'Jorge Mejía Mulhia' => 'jorge.mejia@konfio.mx',
    'Luis Genaro Arvizu Vega' => 'luis.arvizu@konfio.mx',
    'Martín González Escamilla' => 'martin.gonzalez@konfio.mx'
   }
  sdk.platform     = :ios, "13.0"

  sdk.source       = { :git => "https://github.com/srpago/srpago_pods.git", :tag => '2.0.0'}
  sdk.vendored_frameworks = 'KNPaymentFramework.xcframework'
  sdk.frameworks = 'KNPaymentFramework'
end
