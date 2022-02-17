//
//  KcvInfo.h
//  PaxEasyLink
//
//  Created by jim.J on 2019/4/2.
//  Copyright © 2019 PAX. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PaxKcvInfo : NSObject

/**
 Kcv mode
 */
@property (nonatomic,assign)Byte kcvcheckMode;

/**
 KCV LEN
 */
@property (nonatomic,assign)Byte Kcvlen;

/**
 Kcv value
 */
@property (nonatomic,copy)NSData *KcvValue;
@end

NS_ASSUME_NONNULL_END
