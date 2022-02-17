//
//  ReportResponse.h
//  PaxEasyLink
//
//  Created by jim.J on 2019/4/1.
//  Copyright © 2019 PAX. All rights reserved.
//

#import <Foundation/Foundation.h>
//status
#define SUCCESS @"SUCCESS";
#define CANCEL  @"CANCEL";
#define TIMEOUT @"TIMEOUT";
#define NO_APP  @"NO_APP";

NS_ASSUME_NONNULL_BEGIN

@interface PaxReportResponse : NSObject
@property (nonatomic,copy)NSString *status;
@property (nonatomic,copy)NSString *appLabel;
@property (nonatomic,assign)NSInteger appIndex;

@end

NS_ASSUME_NONNULL_END
