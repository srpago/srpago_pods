#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.4.2 (swiftlang-1205.0.28.2 clang-1205.0.19.57)
#ifndef READERMODULE_SWIFT_H
#define READERMODULE_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreBluetooth;
@import Foundation;
@import ObjectiveC;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="ReaderModule",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class NSString;
@class NSNumber;

SWIFT_CLASS_NAMED("BrandCardManager")
@interface BrandCardManager : NSObject
/// This method verifies if the brand is owned of Mastercard
/// \param brand String name of brand card
///
///
/// returns:
/// Boolean indicated if this brand card is Mastercard
- (BOOL)isMasterCardWithBrand:(NSString * _Nonnull)brand SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// Connection is a class that is in charge of netwrorking layer and allows you make easy httRequest to implement REST services in your application.
SWIFT_CLASS("_TtC12ReaderModule10Connection")
@interface Connection : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// A object that provides information to make REST connection.
SWIFT_CLASS("_TtC12ReaderModule17ConnectionRequest")
@interface ConnectionRequest : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC12ReaderModule15LocationService")
@interface LocationService : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC12ReaderModule14MonthlyPayment")
@interface MonthlyPayment : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class NewRelicLoggerOptions;
enum CardType : NSInteger;
enum Currency : NSInteger;
enum ReaderTypes : NSInteger;

SWIFT_CLASS("_TtC12ReaderModule14NewRelicLogger")
@interface NewRelicLogger : NSObject
- (nonnull instancetype)initWithOptions:(NewRelicLoggerOptions * _Nonnull)options OBJC_DESIGNATED_INITIALIZER;
+ (void)configureWithInsertKey:(NSString * _Nonnull)insertKey;
- (void)logLoginEventWithUserEmail:(NSString * _Nonnull)userEmail;
- (void)logLoginEventWithProductToken:(NSString * _Nonnull)productToken;
- (void)logTransactionEventWithAmount:(float)amount cardType:(enum CardType)cardType commision:(float)commision currency:(enum Currency)currency latitude:(float)latitude longitude:(float)longitude makePaymentFailReason:(NSString * _Nonnull)makePaymentFailReason msi:(NSInteger)msi readerBatteryPercentage:(NSInteger)readerBatteryPercentage readerFirmware:(NSString * _Nonnull)readerFirmware readerHardware:(NSString * _Nonnull)readerHardware readerIsCharging:(BOOL)readerIsCharging readerType:(enum ReaderTypes)readerType readerAppOsName:(NSString * _Nullable)readerAppOsName readerOsVersion:(NSString * _Nullable)readerOsVersion reference:(NSString * _Nonnull)reference status:(NSString * _Nonnull)status tip:(float)tip total:(float)total transactionTime:(NSString * _Nullable)transactionTime serverResponseTime:(NSString * _Nullable)serverResponseTime deviceConnectionTime:(NSString * _Nullable)deviceConnectionTime user:(NSString * _Nonnull)user TLVsTags:(NSDictionary<NSString *, id> * _Nullable)TLVsTags bin:(NSString * _Nullable)bin transactionId:(NSString * _Nullable)transactionId entryMode:(NSString * _Nullable)entryMode;
- (void)addUserDataWithUser:(NSString * _Nonnull)user commission:(float)commission;
- (void)addLocationDataWithLatitude:(float)latitude longitude:(float)longitude;
- (void)addMSIDataWithMsi:(NSInteger)msi;
- (void)addPaymentDataWithReference:(NSString * _Nonnull)reference total:(float)total tip:(float)tip amount:(float)amount currency:(NSString * _Nonnull)currency;
- (void)addCardDataWithCardType:(NSString * _Nonnull)cardType;
- (void)addCardReaderDataWithReaderType:(enum ReaderTypes)readerType firmware:(NSString * _Nonnull)firmware batteryPercentage:(NSInteger)batteryPercentage serialNumber:(NSString * _Nonnull)serialNumber isCharging:(BOOL)isCharging appOSName:(NSString * _Nullable)appOSName osVersion:(NSString * _Nullable)osVersion;
- (void)closeTransactionWithStatus:(NSString * _Nonnull)status makePaymentFailReason:(NSString * _Nullable)makePaymentFailReason;
- (void)startTransactionTime;
- (void)stopTransactionTime;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end




@interface NewRelicLogger (SWIFT_EXTENSION(ReaderModule))
@end

typedef SWIFT_ENUM(NSInteger, ReaderTypes, open) {
  ReaderTypesUNKNOW = 0,
  ReaderTypesQPOSBluetooth = 1,
  ReaderTypesQPOSAudio = 2,
  ReaderTypesBBPOSBluetooth = 3,
  ReaderTypesBBPOSAudio = 4,
  ReaderTypesPAX = 5,
};

typedef SWIFT_ENUM(NSInteger, CardType, open) {
  CardTypeMasterCard = 0,
  CardTypeVisa = 1,
  CardTypeAmericanExpress = 2,
  CardTypeCarnet = 3,
};

typedef SWIFT_ENUM(NSInteger, Currency, open) {
  CurrencyMXN = 0,
  CurrencyUSD = 1,
};


SWIFT_CLASS("_TtC12ReaderModule21NewRelicLoggerOptions")
@interface NewRelicLoggerOptions : NSObject
- (nonnull instancetype)initWithSdkBuild:(NSString * _Nonnull)sdkBuild OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC12ReaderModule10ReaderInfo")
@interface ReaderInfo : NSObject
@property (nonatomic, readonly) NSInteger readerType;
@property (nonatomic, readonly) NSInteger batteryPercentage;
@property (nonatomic, readonly, copy) NSString * _Nonnull firmwareVersion;
@property (nonatomic, readonly, copy) NSString * _Nonnull hardwareVersion;
@property (nonatomic, readonly, copy) NSString * _Nullable uid;
@property (nonatomic, readonly, copy) NSString * _Nullable serialNumber;
@property (nonatomic, readonly, copy) NSString * _Nullable emvKeyProfileID;
@property (nonatomic, readonly, copy) NSString * _Nullable defaultLanguage;
@property (nonatomic, readonly, copy) NSString * _Nullable pinKeyProfileID;
@property (nonatomic, readonly, copy) NSString * _Nullable firmwareID;
@property (nonatomic, readonly, copy) NSString * _Nullable bootloaderVersion;
@property (nonatomic, readonly, copy) NSString * _Nullable terminalSettingVersion;
@property (nonatomic, readonly, copy) NSString * _Nullable vendorID;
@property (nonatomic, readonly, copy) NSString * _Nullable bID;
@property (nonatomic, readonly, copy) NSString * _Nullable macKeyProfileID;
@property (nonatomic, readonly, copy) NSString * _Nullable pinKsn;
@property (nonatomic, readonly, copy) NSString * _Nullable macKsn;
@property (nonatomic, readonly, copy) NSString * _Nullable supportedLanguages;
@property (nonatomic, readonly, copy) NSString * _Nullable batteryLevel;
@property (nonatomic, readonly, copy) NSString * _Nullable deviceSettingVersion;
@property (nonatomic, readonly, copy) NSString * _Nullable sdkVersion;
@property (nonatomic, readonly, copy) NSString * _Nullable trackKeyProfileID;
@property (nonatomic, readonly, copy) NSString * _Nullable emvKsn;
@property (nonatomic, readonly, copy) NSString * _Nullable formatID;
@property (nonatomic, readonly, copy) NSString * _Nullable trackKsn;
@property (nonatomic, readonly, copy) NSString * _Nullable productID;
@end

@class CBPeripheral;
enum ReaderType : NSInteger;
enum ReaderSate : NSInteger;
@class ReaderPayment;
@class ServerTransaction;
@class UIViewController;

SWIFT_CLASS_NAMED("ReaderModule")
@interface ReaderModule : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) ReaderModule * _Nonnull shared;)
+ (ReaderModule * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
+ (void)setSandboxEnvironmentWithSandbox:(BOOL)sandbox;
- (void)searchBluetoothReadersWithDevices:(void (^ _Nonnull)(NSArray<CBPeripheral *> * _Nonnull))devices error:(void (^ _Nonnull)(NSError * _Nonnull))error;
- (void)connectWithDevice:(CBPeripheral * _Nonnull)device;
- (void)connectWithFakeWithDeviceName:(NSString * _Nonnull)deviceName;
- (void)connectAudioWithVersion:(enum ReaderType)version;
- (void)readerStateDidChangeWithCompletion:(void (^ _Nullable)(enum ReaderSate))completion error:(void (^ _Nonnull)(NSError * _Nonnull))error;
- (void)requestReaderInfoWithInfo:(void (^ _Nonnull)(ReaderInfo * _Nonnull))info;
- (ReaderInfo * _Nonnull)getCachedReaderInfo SWIFT_WARN_UNUSED_RESULT;
- (void)connectLastPaired;
- (void)removeLastPaired;
- (BOOL)isReaderPaired SWIFT_WARN_UNUSED_RESULT;
- (BOOL)isConnected SWIFT_WARN_UNUSED_RESULT;
- (void)cancelTransaction;
- (void)createPaymentWithPayment:(ReaderPayment * _Nonnull)payment processing:(void (^ _Nonnull)(BOOL))processing msiPromos:(void (^ _Nonnull)(NSArray<MonthlyPayment *> * _Nonnull))msiPromos result:(void (^ _Nonnull)(ServerTransaction * _Nonnull))result error:(void (^ _Nonnull)(NSError * _Nonnull))error vc:(UIViewController * _Nullable)vc;
- (void)showPaymentController:(UIViewController * _Nonnull)from payment:(ReaderPayment * _Nonnull)payment success:(void (^ _Nonnull)(ServerTransaction * _Nonnull))success error:(void (^ _Nonnull)(NSError * _Nonnull))error;
- (void)paymentAddMSIWithMonthlyPayment:(MonthlyPayment * _Nullable)monthlyPayment;
- (void)sendtTicketWithOperationID:(NSString * _Nonnull)operationID mail:(NSString * _Nullable)mail phone:(NSString * _Nullable)phone success:(void (^ _Nonnull)(void))success error:(void (^ _Nonnull)(NSError * _Nonnull))error;
@end



SWIFT_CLASS("_TtC12ReaderModule13ReaderPayment")
@interface ReaderPayment : NSObject
- (nonnull instancetype)initWithAmount:(float)amount reference:(NSString * _Nonnull)reference tip:(float)tip OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

typedef SWIFT_ENUM(NSInteger, ReaderSate, open) {
  ReaderSateConnecting = 0,
  ReaderSateConnected = 1,
  ReaderSateDisconnected = 2,
  ReaderSateWaitingCard = 3,
  ReaderSateCardDetected = 4,
  ReaderSateSetPin = 5,
  ReaderSateRemoveCard = 6,
  ReaderSateCardRemoved = 7,
};

typedef SWIFT_ENUM(NSInteger, ReaderType, open) {
  ReaderTypeUnknow = 0,
  ReaderTypeQposBluetooth = 1,
  ReaderTypeQposAudio = 2,
  ReaderTypeBbposBluetooth = 3,
  ReaderTypeBbposAudio = 4,
  ReaderTypePax = 5,
  ReaderTypeFake = 6,
};

@class NSBundle;
@class NSCoder;

SWIFT_CLASS("_TtC12ReaderModule23SelectionViewController")
@interface SelectionViewController : UIViewController
- (void)viewDidLoad;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


@class CBCentralManager;

@interface SelectionViewController (SWIFT_EXTENSION(ReaderModule)) <CBCentralManagerDelegate>
- (void)centralManagerDidUpdateState:(CBCentralManager * _Nonnull)central;
@end


SWIFT_CLASS("_TtC12ReaderModule17ServerTransaction")
@interface ServerTransaction : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif

#elif defined(__ARM_ARCH_7A__) && __ARM_ARCH_7A__
// Generated by Apple Swift version 5.4.2 (swiftlang-1205.0.28.2 clang-1205.0.19.57)
#ifndef READERMODULE_SWIFT_H
#define READERMODULE_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreBluetooth;
@import Foundation;
@import ObjectiveC;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="ReaderModule",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class NSString;
@class NSNumber;

SWIFT_CLASS_NAMED("BrandCardManager")
@interface BrandCardManager : NSObject
/// This method verifies if the brand is owned of Mastercard
/// \param brand String name of brand card
///
///
/// returns:
/// Boolean indicated if this brand card is Mastercard
- (BOOL)isMasterCardWithBrand:(NSString * _Nonnull)brand SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// Connection is a class that is in charge of netwrorking layer and allows you make easy httRequest to implement REST services in your application.
SWIFT_CLASS("_TtC12ReaderModule10Connection")
@interface Connection : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// A object that provides information to make REST connection.
SWIFT_CLASS("_TtC12ReaderModule17ConnectionRequest")
@interface ConnectionRequest : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC12ReaderModule15LocationService")
@interface LocationService : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC12ReaderModule14MonthlyPayment")
@interface MonthlyPayment : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class NewRelicLoggerOptions;
enum CardType : NSInteger;
enum Currency : NSInteger;
enum ReaderTypes : NSInteger;

SWIFT_CLASS("_TtC12ReaderModule14NewRelicLogger")
@interface NewRelicLogger : NSObject
- (nonnull instancetype)initWithOptions:(NewRelicLoggerOptions * _Nonnull)options OBJC_DESIGNATED_INITIALIZER;
+ (void)configureWithInsertKey:(NSString * _Nonnull)insertKey;
- (void)logLoginEventWithUserEmail:(NSString * _Nonnull)userEmail;
- (void)logLoginEventWithProductToken:(NSString * _Nonnull)productToken;
- (void)logTransactionEventWithAmount:(float)amount cardType:(enum CardType)cardType commision:(float)commision currency:(enum Currency)currency latitude:(float)latitude longitude:(float)longitude makePaymentFailReason:(NSString * _Nonnull)makePaymentFailReason msi:(NSInteger)msi readerBatteryPercentage:(NSInteger)readerBatteryPercentage readerFirmware:(NSString * _Nonnull)readerFirmware readerHardware:(NSString * _Nonnull)readerHardware readerIsCharging:(BOOL)readerIsCharging readerType:(enum ReaderTypes)readerType readerAppOsName:(NSString * _Nullable)readerAppOsName readerOsVersion:(NSString * _Nullable)readerOsVersion reference:(NSString * _Nonnull)reference status:(NSString * _Nonnull)status tip:(float)tip total:(float)total transactionTime:(NSString * _Nullable)transactionTime serverResponseTime:(NSString * _Nullable)serverResponseTime deviceConnectionTime:(NSString * _Nullable)deviceConnectionTime user:(NSString * _Nonnull)user TLVsTags:(NSDictionary<NSString *, id> * _Nullable)TLVsTags bin:(NSString * _Nullable)bin transactionId:(NSString * _Nullable)transactionId entryMode:(NSString * _Nullable)entryMode;
- (void)addUserDataWithUser:(NSString * _Nonnull)user commission:(float)commission;
- (void)addLocationDataWithLatitude:(float)latitude longitude:(float)longitude;
- (void)addMSIDataWithMsi:(NSInteger)msi;
- (void)addPaymentDataWithReference:(NSString * _Nonnull)reference total:(float)total tip:(float)tip amount:(float)amount currency:(NSString * _Nonnull)currency;
- (void)addCardDataWithCardType:(NSString * _Nonnull)cardType;
- (void)addCardReaderDataWithReaderType:(enum ReaderTypes)readerType firmware:(NSString * _Nonnull)firmware batteryPercentage:(NSInteger)batteryPercentage serialNumber:(NSString * _Nonnull)serialNumber isCharging:(BOOL)isCharging appOSName:(NSString * _Nullable)appOSName osVersion:(NSString * _Nullable)osVersion;
- (void)closeTransactionWithStatus:(NSString * _Nonnull)status makePaymentFailReason:(NSString * _Nullable)makePaymentFailReason;
- (void)startTransactionTime;
- (void)stopTransactionTime;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end




@interface NewRelicLogger (SWIFT_EXTENSION(ReaderModule))
@end

typedef SWIFT_ENUM(NSInteger, ReaderTypes, open) {
  ReaderTypesUNKNOW = 0,
  ReaderTypesQPOSBluetooth = 1,
  ReaderTypesQPOSAudio = 2,
  ReaderTypesBBPOSBluetooth = 3,
  ReaderTypesBBPOSAudio = 4,
  ReaderTypesPAX = 5,
};

typedef SWIFT_ENUM(NSInteger, CardType, open) {
  CardTypeMasterCard = 0,
  CardTypeVisa = 1,
  CardTypeAmericanExpress = 2,
  CardTypeCarnet = 3,
};

typedef SWIFT_ENUM(NSInteger, Currency, open) {
  CurrencyMXN = 0,
  CurrencyUSD = 1,
};


SWIFT_CLASS("_TtC12ReaderModule21NewRelicLoggerOptions")
@interface NewRelicLoggerOptions : NSObject
- (nonnull instancetype)initWithSdkBuild:(NSString * _Nonnull)sdkBuild OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC12ReaderModule10ReaderInfo")
@interface ReaderInfo : NSObject
@property (nonatomic, readonly) NSInteger readerType;
@property (nonatomic, readonly) NSInteger batteryPercentage;
@property (nonatomic, readonly, copy) NSString * _Nonnull firmwareVersion;
@property (nonatomic, readonly, copy) NSString * _Nonnull hardwareVersion;
@property (nonatomic, readonly, copy) NSString * _Nullable uid;
@property (nonatomic, readonly, copy) NSString * _Nullable serialNumber;
@property (nonatomic, readonly, copy) NSString * _Nullable emvKeyProfileID;
@property (nonatomic, readonly, copy) NSString * _Nullable defaultLanguage;
@property (nonatomic, readonly, copy) NSString * _Nullable pinKeyProfileID;
@property (nonatomic, readonly, copy) NSString * _Nullable firmwareID;
@property (nonatomic, readonly, copy) NSString * _Nullable bootloaderVersion;
@property (nonatomic, readonly, copy) NSString * _Nullable terminalSettingVersion;
@property (nonatomic, readonly, copy) NSString * _Nullable vendorID;
@property (nonatomic, readonly, copy) NSString * _Nullable bID;
@property (nonatomic, readonly, copy) NSString * _Nullable macKeyProfileID;
@property (nonatomic, readonly, copy) NSString * _Nullable pinKsn;
@property (nonatomic, readonly, copy) NSString * _Nullable macKsn;
@property (nonatomic, readonly, copy) NSString * _Nullable supportedLanguages;
@property (nonatomic, readonly, copy) NSString * _Nullable batteryLevel;
@property (nonatomic, readonly, copy) NSString * _Nullable deviceSettingVersion;
@property (nonatomic, readonly, copy) NSString * _Nullable sdkVersion;
@property (nonatomic, readonly, copy) NSString * _Nullable trackKeyProfileID;
@property (nonatomic, readonly, copy) NSString * _Nullable emvKsn;
@property (nonatomic, readonly, copy) NSString * _Nullable formatID;
@property (nonatomic, readonly, copy) NSString * _Nullable trackKsn;
@property (nonatomic, readonly, copy) NSString * _Nullable productID;
@end

@class CBPeripheral;
enum ReaderType : NSInteger;
enum ReaderSate : NSInteger;
@class ReaderPayment;
@class ServerTransaction;
@class UIViewController;

SWIFT_CLASS_NAMED("ReaderModule")
@interface ReaderModule : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) ReaderModule * _Nonnull shared;)
+ (ReaderModule * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
+ (void)setSandboxEnvironmentWithSandbox:(BOOL)sandbox;
- (void)searchBluetoothReadersWithDevices:(void (^ _Nonnull)(NSArray<CBPeripheral *> * _Nonnull))devices error:(void (^ _Nonnull)(NSError * _Nonnull))error;
- (void)connectWithDevice:(CBPeripheral * _Nonnull)device;
- (void)connectWithFakeWithDeviceName:(NSString * _Nonnull)deviceName;
- (void)connectAudioWithVersion:(enum ReaderType)version;
- (void)readerStateDidChangeWithCompletion:(void (^ _Nullable)(enum ReaderSate))completion error:(void (^ _Nonnull)(NSError * _Nonnull))error;
- (void)requestReaderInfoWithInfo:(void (^ _Nonnull)(ReaderInfo * _Nonnull))info;
- (ReaderInfo * _Nonnull)getCachedReaderInfo SWIFT_WARN_UNUSED_RESULT;
- (void)connectLastPaired;
- (void)removeLastPaired;
- (BOOL)isReaderPaired SWIFT_WARN_UNUSED_RESULT;
- (BOOL)isConnected SWIFT_WARN_UNUSED_RESULT;
- (void)cancelTransaction;
- (void)createPaymentWithPayment:(ReaderPayment * _Nonnull)payment processing:(void (^ _Nonnull)(BOOL))processing msiPromos:(void (^ _Nonnull)(NSArray<MonthlyPayment *> * _Nonnull))msiPromos result:(void (^ _Nonnull)(ServerTransaction * _Nonnull))result error:(void (^ _Nonnull)(NSError * _Nonnull))error vc:(UIViewController * _Nullable)vc;
- (void)showPaymentController:(UIViewController * _Nonnull)from payment:(ReaderPayment * _Nonnull)payment success:(void (^ _Nonnull)(ServerTransaction * _Nonnull))success error:(void (^ _Nonnull)(NSError * _Nonnull))error;
- (void)paymentAddMSIWithMonthlyPayment:(MonthlyPayment * _Nullable)monthlyPayment;
- (void)sendtTicketWithOperationID:(NSString * _Nonnull)operationID mail:(NSString * _Nullable)mail phone:(NSString * _Nullable)phone success:(void (^ _Nonnull)(void))success error:(void (^ _Nonnull)(NSError * _Nonnull))error;
@end



SWIFT_CLASS("_TtC12ReaderModule13ReaderPayment")
@interface ReaderPayment : NSObject
- (nonnull instancetype)initWithAmount:(float)amount reference:(NSString * _Nonnull)reference tip:(float)tip OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

typedef SWIFT_ENUM(NSInteger, ReaderSate, open) {
  ReaderSateConnecting = 0,
  ReaderSateConnected = 1,
  ReaderSateDisconnected = 2,
  ReaderSateWaitingCard = 3,
  ReaderSateCardDetected = 4,
  ReaderSateSetPin = 5,
  ReaderSateRemoveCard = 6,
  ReaderSateCardRemoved = 7,
};

typedef SWIFT_ENUM(NSInteger, ReaderType, open) {
  ReaderTypeUnknow = 0,
  ReaderTypeQposBluetooth = 1,
  ReaderTypeQposAudio = 2,
  ReaderTypeBbposBluetooth = 3,
  ReaderTypeBbposAudio = 4,
  ReaderTypePax = 5,
  ReaderTypeFake = 6,
};

@class NSBundle;
@class NSCoder;

SWIFT_CLASS("_TtC12ReaderModule23SelectionViewController")
@interface SelectionViewController : UIViewController
- (void)viewDidLoad;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


@class CBCentralManager;

@interface SelectionViewController (SWIFT_EXTENSION(ReaderModule)) <CBCentralManagerDelegate>
- (void)centralManagerDidUpdateState:(CBCentralManager * _Nonnull)central;
@end


SWIFT_CLASS("_TtC12ReaderModule17ServerTransaction")
@interface ServerTransaction : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif

#endif
