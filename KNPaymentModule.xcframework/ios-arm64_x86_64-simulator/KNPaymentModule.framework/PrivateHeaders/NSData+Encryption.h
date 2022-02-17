//
//  NSData+NSData_Encryption.h
//  DemoCrypt
//
//  Created by Christian on 5/27/15.
//  Copyright (c) 2015 SrPago. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (NSData_Encryption)
- (NSData*)AES256EncryptWithKey:(NSString*)key ;

@end
