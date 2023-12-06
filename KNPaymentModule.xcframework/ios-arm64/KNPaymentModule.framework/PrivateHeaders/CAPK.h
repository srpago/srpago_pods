//
//  CAPK.h
//
//  Created by Alex Wong on 2017-08-18.
//  Copyright 2017 BBPOS LTD. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CAPK : NSObject{
    NSString *location;
    NSString *index;
    NSString *size;
    NSString *rid;
    NSString *modulus;
    NSString *exponent;
    NSString *checksum;
}

@property (nonatomic, retain) NSString *location;
@property (nonatomic, retain) NSString *index;
@property (nonatomic, retain) NSString *size;
@property (nonatomic, retain) NSString *rid;
@property (nonatomic, retain) NSString *modulus;
@property (nonatomic, retain) NSString *exponent;
@property (nonatomic, retain) NSString *checksum;

@end
