//
//  HFSmartSP.h
//  LibHFSmart
//
//  Created by Pishum on 16/1/19.
//  Copyright © 2016年 Pishum. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HFSmartSP : NSObject

//读取排插所有节点的状态信息：
+ (NSString*)sendHFSPStateWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

//打开排插
+ (NSString*)sendHFSPOpenWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

//关闭排插
+ (NSString*)sendHFSPCloseWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

//获取定时任务信息
+ (NSString*)getHFSPTimeTaskWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

/*设置定时任务信息
 order="HFSPTIMETASK=1,01FF1230"
 1表示上下层（1上层2下层）
*/
+ (NSString*)setHFSPTimeTaskWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

/*
 得到设置定时任务的信息 arg0:任务编号(0-F) arg1:1开2关(1或2) arg2:1使能0取消(1或0)
 arg3:星期从左到右依次：6543217,重复为1，不重复0(例如:0000001星期天重复)
 arg4:十进制时间
 */
+ (NSString*)getHFSPTimeTaskStrWithArg0:(NSString*)arg0 Arg1:(NSString*)arg1 Arg2:(NSString*)arg2 Arg3:(NSString*)arg3 Arg4:(NSString*)arg4;

/*
 获取延时任务信息需要发送的
 */
+ (NSString*)getHFSPTimeShutWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;


/*设置延时任务
 例如:
 order="HFSPTIMESHUT=1,0,时间"
 1 表示上下层:1上2下
 0 代表延时开关:0关 1开 2不执行该任务
 时间是0-999，单位分钟(十进制表示)
 */
+ (NSString *)setHFSPTimeShutWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;


//获取智能插座时间所需发送的指令
+ (NSString*)getHFSPTimeWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

/*设置插座时间所需要发送的指令
 order="HFSPTIME=13-10-15 15:54:00"
 后面的参数格式按照
 YY-MM-DD HH:MM:SS
 */
+ (NSString*)setHFSPTimeWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;


/*更改密码 设置新密码
 order="HFSPUPDATEPWD=888888"
 后面的密码是NSString 格式的6位整形数字
 */
+ (NSString*)sendHFSPUpdatePwdWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

/*比较密码 对比密码正确与否
 order="HFSPCMPPWD=888888"
 后面的密码是6位整形字符串
 */
+ (NSString*)sendHFSPCmpPwdWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;



//HFAPSTA获取当前模式  AP或者STA
+ (NSString*)getHFSPModeAPOrSTAWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

/*设置模式
 order="HFSPAPSTA=0"
 后面参数:
 0：切换到STA
 1：切换到AP
 */
+ (NSString*)setHFSPModeAPOrSTAWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

//HFV读取硬件版本号
+ (NSString*)getHFSPVerionWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

/*HFSPUPDATE固件升级
 arg0:"HFSPUPDATE=v1.0.1t23701(a)"
 v1.0.1t23701(a)需要升级的新的版本号
 */
+ (NSString*)sendHFSPUpdateWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;

//获取当前可升级的固件信息 根据不同语言获取，目前支持 cn,en,hk,tw
+ (NSMutableArray*)getHFSPFirmWareArrayWithLanguage:(NSString*)language;


//HFSPDFT恢复出厂
+ (NSString*)sendHFSPDFTWithOrder:(NSString*)order Mac:(NSString*)mac Net:(NSString*)network Pwd:(NSString*)passwd;


/************************* 根据密文得到状态信息 *********************/
//HFSPSTATE
+ (NSMutableArray*)getHFSPStateInfoWithSec:(NSData*)enSec;
+ (NSMutableArray*)getHFSPTimeTaskInfoWithSec:(NSData*)enSec;

/*将得到的定时任务信息的16进制格式进行解析
 返回长度为5的array，代表信息依次是
 1使能，2取消
 星期6543217
 1开2关
 时
 分
 */
+ (NSMutableArray*)SPhexTimeTaskToBitTimeTask:(NSString*)hexTask;

//HFSPTIMESHUT
+ (NSMutableArray *)getHFSPTimeShutInfoWithSec:(NSData*)enSec;

//HFSPTIME
+ (NSMutableArray *)getHFSPTimeInfoWithSec:(NSData*)enSec;

//HFSPUPDATEPWD
+ (NSMutableArray *)getHFSPUpdatePwdInfoWithSec:(NSData*)enSec;

//HFSPCMPPWD
+ (NSMutableArray *)getHFSPCmpPwdInfoWithSec:(NSData*)enSec;

//HFSPAPSTA
+(NSMutableArray *)getHFSPAPSTAInfoWithSec:(NSData*)enSec;

//HFSPV
+ (NSMutableArray*)getHFSPVInfoWithSec:(NSData*)enSec;

//HFSPUPDATE
+ (NSMutableArray*)getHFSPUpdateInfoWithSec:(NSData*)enSec;

//HFSPPWD
+ (NSMutableArray*)getHFPwdErrInfoWithSec:(NSData*)enSec;
@end
