# SrPago-SDK

Modules:
 - KNPaymentFramework

## Requirements

- Xcode 12.5
- Swift 5
- Minimum iOS 11 version supported
- Cocoapods
- iPhones and iPads supported

# ChangeLog

## [2.4.0] 2022-04-27

## Added
- Get user email when his SSO token was added

## [2.3.0] 2022-04-27

## Added
- OTA improvements 

## [2.2.1] 2022-04-21

## Added
- OTA Update

## [2.1.1] 2022-03-23

## Bugfix
- Error launched if turn off your reader when transaction was finished

## [2.1.0] 2022-03-18

## Changed
- Singleton was removed from kNPayment

## [2.0.14] 2022-03-17

## Changed
- Build with build library for distribution

## [2.0.13] 2022-03-16

## Changed
- Build with swift 5.6

## [2.0.12] 2022-03-12

## Changed
- Signature header height can be configurated

## Fixed
- Double error thrown when configuration service has an error

## [2.0.11] 2022-03-10

## Changed
- AppKey and AppSecret will be changed to optionals

## [2.0.10] 2022-03-08

## Removed
- Unnecessary reader states callbacks

## [2.0.9] 2022-03-08

## Changed
- Reader info was improved

## Added
- Validation of location enable


## [2.0.8] 2022-03-03

## Changed
- Vinculation was improved, now turn off readers will be dissapear from vinculation list

## [2.0.7] 2022-03-03

## Changed
- Signature UI Configuration

## [2.0.6] 2022-03-02

## Added
- OTA Update

## [2.0.5] 2022-02-28

## Added
- Signature UI Configuration

## [2.0.4] 2022-02-28

## Fixed
- Reader state was fixed when reader was linked from try to reconnect without previous descovery
 
## [2.0.2] 2022-02-25

## Fixed
- Fix publish on app store

## [2.0.1] 2022-02-21

## Changed
- Build library for distribution was disable

## [2.0.0] 2022-02-02

## Added
- New Framework version
- Simulator support

## [1.2.0] 2022-02-01

## Added
- New environments support
- Battery report was improved

## [1.1.9] 2022-01-06

### Added
- PAX vinculated info was improved

### Changed
- Support for Xcode 13 and iOS 15
- Minimum iOS version was changed to 11

## [1.1.8] 2021-09-11

### Added
- Adding MSI value on Receipt
- Refound consume service

### Changed
- Brand card BBPOSManager
- Update headers according to environment
- Reader time transaction was changed from 120 seconds to 30 from BBPOS Reader

### Fixed
- Logging the 'SUCCESS' status on transacation
- Null value crash in PAX print
- Validating empty fields of address to avoid show wrong string address

## [1.1.7] 2021-08-31

### Added
- Transaction web service, return transactions values
- Add ISO field in Bluetooth and WIFI ticket
- Reference field is now limited to 20 characters
- Headers for each web service
- Decrypt Method for base url

### Fixed
- Generic Printer works again

### Removed
- Old Readers were removed

## [1.1.6] 2021-07-15

### Added

- Master Card **Sonicbrand** Sound
- Unit Tests

## Removed
- Unusable class was removed
