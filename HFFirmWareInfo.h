//
//  HFFirmWareInfo.h
//  LibHFSmart
//
//  Created by Pishum on 16/1/19.
//  Copyright © 2016年 Pishum. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HFFirmWareInfo : NSObject
@property (strong,nonatomic)NSString *date;
@property (strong,nonatomic)NSString *version;
@property (strong,nonatomic)NSString *info;
@property (strong,nonatomic)NSString *versionCode;
@property (strong,nonatomic)NSString *versionDetail;

+ (HFFirmWareInfo*)initHFFirmWareInfoWithData:(NSString*)date Version:(NSString*)version Info:(NSString*)info Code:(NSString*)code Detail:(NSString*)detail;
@end
