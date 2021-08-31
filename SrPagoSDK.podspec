Pod::Spec.new do |sdk|

  sdk.name         = "SrPagoSDK"
  sdk.version      = "1.1.7"
  sdk.summary      = "SDK de Sr.pago"
  sdk.description  = <<-DESC
    SDK de Señor pago para iOS
                   DESC

  sdk.homepage     = "https://srpago.com"

  sdk.license      = { :type => "MIT", :text => "© 2021 SrPago" }

  sdk.authors      = {
    'Fernando Bustos' => 'fbustosr@srpago.com',
    'Jorge Mejia' => 'jmejiah@srpago.com'
    'Genaro Arvizu' => 'lgarvizuv@srpago.com',
    'Martín Gonzales' => 'mgonzaleze@srpago.com'
   }
  sdk.platform     = :ios, "9.0"

  sdk.source       = { :git => "https://github.com/srpago/srpago_pods.git",:tag => '1.1.7'}
  sdk.default_subspec = 'Core'

    sdk.subspec 'Core' do |core|
        core.vendored_frameworks = "SrPagoSDK.framework"
    end

    sdk.subspec 'Ecommerce' do |ecommerce|
        ecommerce.vendored_frameworks = "EcommerceModule.framework"
        ecommerce.dependency 'SrPagoSDK/Core'
    end

    sdk.subspec 'Reader' do |reader|
        reader.vendored_frameworks = "ReaderModule.framework"
        reader.dependency 'SrPagoSDK/Core'
    end


end
