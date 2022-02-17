//
//  RSA.h
//  DemoCrypt
//
//  Created by Christian on 4/23/15.
//  Copyright (c) 2015 SrPago. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>
@interface RSA : NSObject {
}
+ (NSString *)encryptString:(NSString *)str publicKey:(NSString *)pubKey;
+ (NSString *)encryptData:(NSData *)data publicKey:(NSString *)pubKey;


@end
