//
//  HFSmartSocket.h
//  LibHFSmart
//
//  Created by Pishum on 16/1/18.
//  Copyright © 2016年 Pishum. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface HFSmartSocket : NSObject

+ (NSString*)sendHFStateWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;
+ (NSString*)sendHFOpenWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;
+ (NSString*)sendHFCloseWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

+ (NSString*)getHFTimeTaskWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;
+ (NSString*)setHFTimeTaskWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

/*
 得到设置定时任务的信息 arg0:任务编号(0-F) arg1:1开2关(1或2) arg2:1使能0取消(1或0)
 arg3:星期从左到右依次：6543217,重复为1，不重复0(例如:0000001星期天重复)
 arg4:十进制时间
 */
+ (NSString*)getHFTimeTaskStrWithArg0:(NSString*)arg0 Arg1:(NSString*)arg1 Arg2:(NSString*)arg2 Arg3:(NSString*)arg3 Arg4:(NSString*)arg4;

/*
 获取延时任务信息需要发送的
*/
+ (NSString*)getHFTimeShutWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;


/*设置延时任务
 例如:
 order="HFTIMESHUT=0,时间"
 0代表延时关
 1代表延时开
 2代表不执行该延时任务
 时间是0-999，单位分钟(十进制表示)
 */
+ (NSString *)setHFTimeShutWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;


//获取智能插座时间所需发送的指令
+ (NSString*)getHFTimeWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

/*设置插座时间所需要发送的指令
 order="HFTIME=13-10-15 15:54:00"
 后面的参数格式按照
 YY-MM-DD HH:MM:SS
*/
+ (NSString*)setHFTimeWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;


/*更改密码 设置新密码
 order="HFUPDATEPWD=888888"
 后面的密码是NSString 格式的6位整形数字
*/
+ (NSString*)sendHFUpdatePwdWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

/*比较密码 对比密码正确与否
 order="HFCMPPWD=888888"
 后面的密码是6位整形字符串
*/
+ (NSString*)sendHFCmpPwdWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;



//HFAPSTA获取当前模式  AP或者STA
+ (NSString*)getHFModeAPOrSTAWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

/*设置模式
 order="HFAPSTA=0"
 后面参数:
 0：切换到STA
 1：切换到AP
*/
+ (NSString*)setHFModeAPOrSTAWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

//HFV读取硬件版本号
+ (NSString*)getHFVerionWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

/*HFUPDATE固件升级
 arg0:"HFUPDATE=v1.0.1t23701(a)"   
 v1.0.1t23701(a)需要升级的新的版本号
*/
+ (NSString*)sendHFUpdateWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

//获取当前可升级的固件信息 根据不同语言获取，目前支持 cn,en,hk,tw
+ (NSMutableArray*)getHFFirmWareArrayWithLanguage:(NSString*)language;


//HFDFT恢复出厂
+ (NSString*)sendHFDFTWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;


/************************* 根据密文得到状态信息 *********************/
//HFSTATE
+ (NSMutableArray*)getHFStateInfoWithSec:(NSData*)enSec;
+ (NSMutableArray*)getHFTimeTaskInfoWithSec:(NSData*)enSec;

/*将得到的定时任务信息的16进制格式进行解析 
 返回长度为5的array，代表信息依次是
 1使能，2取消
 星期6543217
 1开2关
 时
 分
*/
+ (NSMutableArray*)hexTimeTaskToBitTimeTask:(NSString*)hexTask;


//HFTIMESHUT
+ (NSMutableArray *)getHFTimeShutInfoWithSec:(NSData*)enSec;

//HFTIME
+ (NSMutableArray *)getHFTimeInfoWithSec:(NSData*)enSec;

//HFUPDATEPWD
+ (NSMutableArray *)getHFUpdatePwdInfoWithSec:(NSData*)enSec;

//HFCMPPWD
+ (NSMutableArray *)getHFCmpPwdInfoWithSec:(NSData*)enSec;

//HFAPSTA
+(NSMutableArray *)getHFAPSTAInfoWithSec:(NSData*)enSec;

//HFV
+ (NSMutableArray*)getHFVInfoWithSec:(NSData*)enSec;

//HFUPDATE
+ (NSMutableArray*)getHFUpdateInfoWithSec:(NSData*)enSec;

//HFPWD
+ (NSMutableArray*)getHFPwdErrInfoWithSec:(NSData*)enSec;

@end
