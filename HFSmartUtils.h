//
//  HFSmartUtils.h
//  LibHFSmart
//
//  Created by Pishum on 16/1/15.
//  Copyright © 2016年 Pishum. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MAN @"MAN"
#define WAN @"WAN"



@interface HFSmartUtils : NSObject



+ (NSString*)HFDecodeWithData:(NSData*)data;
+ (NSString*)sendHFServCloudTimeOrder;
+ (NSString*)sendHFServLinkOrderWithMac:(NSString*)mac;
+ (NSString*)sendHFConnectServCloudWithSec:(NSData*)secData;

+ (NSMutableArray*)getHFLinkInfoWithSec:(NSData*)secData;
+ (NSString*)getHFServCloudTimeInfoWithSec:(NSData*)secData;


@end


