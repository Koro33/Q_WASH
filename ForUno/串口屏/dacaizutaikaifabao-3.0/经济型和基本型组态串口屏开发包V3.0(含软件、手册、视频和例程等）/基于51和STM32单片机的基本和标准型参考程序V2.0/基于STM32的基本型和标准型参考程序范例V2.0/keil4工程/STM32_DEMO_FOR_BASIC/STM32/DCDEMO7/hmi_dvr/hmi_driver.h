#ifndef _HMI_DRIVER_
#define _HMI_DRIVER_
  
#include "hmi_user_uart.h"

enum CtrlType
{
	kCtrlUnknown=0x0,
	kCtrlButton=0x10,  //按钮
	kCtrlText,  //文本
	kCtrlProgress,  //进度条
	kCtrlSlider,    //滑动条
	kCtrlMeter,  //仪表
	kCtrlDropList, //下拉列表
	kCtrlAnimation, //动画
	kCtrlRTC, //时间显示
	kCtrlChart, //曲线控件
	kCtrlTable, //表格控件
};

/**************************************************************************************************************
* 名    称： delay_ms
* 功    能： 延时n个毫秒，与芯片速度相关
* 入口参数： n-延时时间
* 出口参数： 无
***************************************************************************************************************/
void delay_ms(unsigned int n);
  
/****************************************************************************
* 名    称： SendBeginCMD()
* 功    能： 发送帧头命令
* 入口参数： 无      
* 出口参数： 无
****************************************************************************/
void SendBeginCMD(void);

/****************************************************************************
* 名    称： SendEndCmd()
* 功    能： 发送帧尾命令
* 入口参数： 无      
* 出口参数： 无
****************************************************************************/
void SendEndCmd(void);

/****************************************************************************
* 名    称： SetHandShake()
* 功    能： 握手
* 入口参数： 无      
* 出口参数： 55表示握手成功，否则失败
****************************************************************************/
void SetHandShake(void);

/****************************************************************************
* 名    称： SetFcolor()
* 功    能： 设置前景色
* 入口参数： fcolor  前景色RGB参数   
* 出口参数： 无
****************************************************************************/
void SetFcolor(uint16 fcolor);

/****************************************************************************
* 名    称： SetBcolor()
* 功    能： 设置背景色
* 入口参数： bcolor  背景色RGB参数   
* 出口参数： 无
****************************************************************************/
void SetBcolor(uint16 bcolor);

/****************************************************************************
* 名    称： GUI_CleanScreen()
* 功    能： 清屏
* 入口参数： 无  
* 出口参数： 无
****************************************************************************/
void GUI_CleanScreen(void);

/****************************************************************************
* 名    称： SetTextSpace()
* 功    能： 设置文字行列间距
* 入口参数： x_w     以点为单位的行间距，取值范围00~1F
             y_w     以点为单位的列间距，取值范围00~1F	
* 出口参数： 无
****************************************************************************/
void SetTextSpace(uint8 x_w, uint8 y_w);
/****************************************************************************
* 名    称： DisText_Region()
* 功    能： 限定文本显示范围
* 入口参数： length   文本框限定的长度
	     width    文本框限定的高度
* 出口参数： 无
****************************************************************************/
void SetFont_Region(uint8 enable,uint16 length,uint16 width );

/****************************************************************************
* 名    称： SetFilterColor()
* 功    能： 设置过滤颜色
* 入口参数： fillcolor_dwon   滤除颜色的下限值
             fillcolor_up     滤除颜色的上限值	
* 出口参数： 无
****************************************************************************/
void SetFilterColor(uint16 fillcolor_dwon, uint16 fillcolor_up);


/****************************************************************************
* 名    称： DisText()
* 功    能： 文本显示
* 入口参数： x       以点为单位的X轴坐标值
             y       以点为单位的Y轴坐标值
   		     back    背景色使能
		     font    字库编码
		     strings 写入的汉字字符串
* 出口参数： 无
****************************************************************************/
void DisText(uint16 x, uint16 y,uint8 back,uint8 font,uchar *strings );


/****************************************************************************
* 名    称： DisData()
* 功    能： 数据显示
* 入口参数： x       以点为单位的X轴坐标值
             y       以点为单位的Y轴坐标值
   	     back    背景色使能
	     font    字库编码
	     sdata   写入的数据
* 出口参数： 无
****************************************************************************/
void DisData(uint16 x, uint16 y,uint8 back,uint8 font,uchar sdata );

/****************************************************************************
* 名    称： DisCursor()
* 功    能： 光标显示
* 入口参数： enable
             x        以点为单位的X轴坐标值
             y        以点为单位的Y轴坐标值
   	     length   光标长度
	     width    光标宽度
* 出口参数： 无
****************************************************************************/
void DisCursor(uint8 enable,uint16 x, uint16 y,uint8 length,uint8 width );

/****************************************************************************
* 名    称： DisFull_Image()
* 功    能： 全屏整幅图显示
* 入口参数： image_id   图片ID编号
             masken     屏蔽色使能
* 出口参数： 无
****************************************************************************/
void DisFull_Image(uint16 image_id,uint8 masken);


/****************************************************************************
* 名    称： DisArea_Image()
* 功    能： 区域图片显示
* 入口参数： x          以点为单位的X轴坐标值
             y          以点为单位的Y轴坐标值 
             image_id   图片ID编号
             masken     屏蔽色使能
* 出口参数： 无
****************************************************************************/
void DisArea_Image(uint16 x,uint16 y,uint16 image_id,uint8 masken);

/****************************************************************************
* 名    称： DisCut_Image()
* 功    能： 图片剪切
* 入口参数： x          以点为单位的X轴坐标值
             y          以点为单位的Y轴坐标值 
             image_id   图片编号
             image_x    图片内部X坐标
             image_y    图片内部Y坐标
             image_l    剪切长度
             image_w    剪切宽度
             masken     屏蔽色使能
* 出口参数： 无
****************************************************************************/
void DisCut_Image(uint16 x,uint16 y,uint16 image_id,uint16 image_x,uint16 image_y,
                   uint16 image_l, uint16 image_w,uint8 masken);

/****************************************************************************
* 名    称： DisFlashImgae()
* 功    能： 动画显示
* 入口参数： x               以点为单位的X轴坐标值
             y               以点为单位的Y轴坐标值 
             flashimage_id   GIF动画ID编号         
* 出口参数： 无
****************************************************************************/
void DisFlashImage(uint16 x,uint16 y,uint16 flashimage_id,uint8 enable,uint8 playnum);
/****************************************************************************
* 名    称： GUI_Dot()
* 功    能： 画点
* 入口参数： x       以点为单位的X轴坐标值
             y       以点为单位的Y轴坐标值           
* 出口参数： 无
****************************************************************************/
void GUI_Dot(uint16 x,uint16 y);

/****************************************************************************
* 名    称： GUI_Line()
* 功    能： 画线
* 入口参数： x0      以点为单位的X轴坐标值
             y0      以点为单位的Y轴坐标值    
             x1      以点为单位的X轴坐标值
             y1      以点为单位的Y轴坐标值  
* 出口参数： 无
****************************************************************************/
void GUI_Line(uint16 x0, uint16 y0, uint16 x1, uint16 y1);
/****************************************************************************
* 名    称： GUI_ConDots()
* 功    能： 绘制折线,将指定的坐标点自动连接起来
* 入口参数： mode     0:用前景色描绘 1：用背景色描绘    
	         pDot     指向点的指针   
			 num      数据的个数  
* 出口参数： 无
****************************************************************************/
void GUI_ConDots(uint8 mode,uchar *pDot,uint16 num);
/****************************************************************************
* 名    称： GUI_Circle()
* 功    能： 画空心圆
* 入口参数： x0               以点为单位的X轴坐标值
             y0               以点为单位的Y轴坐标值    
             r                空心圆的半径   
* 出口参数： 无
****************************************************************************/
void GUI_Circle(uint16 x0, uint16 y0, uint16 r);

/****************************************************************************
* 名    称： GUI_CircleFill()
* 功    能： 画实心圆
* 入口参数： x0               以点为单位的X轴坐标值
             y0               以点为单位的Y轴坐标值    
             r                实心圆的半径   
* 出口参数： 无
****************************************************************************/
void GUI_CircleFill(uint16 x0, uint16 y0, uint16 r);

/****************************************************************************
* 名    称： GUI_Rectangle()
* 功    能： 画空心矩形
* 入口参数： x0      以点为单位的空心矩形左上角X坐标值
             y0      以点为单位的空心矩形左上角Y坐标值   
             x1      以点为单位的空心矩形右下角X坐标值
             y1      以点为单位的空心矩形右下角Y坐标值   
* 出口参数： 无
****************************************************************************/
void GUI_Rectangle(uint16 x0, uint16 y0, uint16 x1,uint16 y1 );

/****************************************************************************
* 名    称： RectangleFill()
* 功    能： 画实心矩形
* 入口参数： x0      以点为单位的实心矩形左上角X坐标值
             y0      以点为单位的实心矩形左上角Y坐标值   
             x1      以点为单位的实心矩形右下角X坐标值
             y1      以点为单位的实心矩形右下角Y坐标值   
* 出口参数： 无
****************************************************************************/
void GUI_RectangleFill(uint16 x0, uint16 y0, uint16 x1,uint16 y1 );

/****************************************************************************
* 名    称： GUI_Ellipse()
* 功    能： 画空心椭圆
* 入口参数： x0      以点为单位的空心椭圆最左端X坐标值
             y0      以点为单位的空心椭圆最上端Y坐标值   
             x1      以点为单位的空心椭圆最右端X坐标值
             y1      以点为单位的空心椭圆最下端Y坐标值   
* 出口参数： 无
****************************************************************************/
void GUI_Ellipse (uint16 x0, uint16 y0, uint16 x1,uint16 y1 );

/****************************************************************************
* 名    称： GUI_EllipseFill()
* 功    能： 画实心椭圆
* 入口参数： x0      以点为单位的实心椭圆最左端X坐标值
             y0      以点为单位的实心椭圆最上端Y坐标值   
             x1      以点为单位的实心椭圆最右端X坐标值
             y1      以点为单位的实心椭圆最下端Y坐标值   
* 出口参数： 无
****************************************************************************/
void GUI_EllipseFill (uint16 x0, uint16 y0, uint16 x1,uint16 y1 );

/****************************************************************************
* 名    称： SetBackLight()
* 功    能： 背光调节
* 入口参数： light_level
* 出口参数： 无
****************************************************************************/
void SetBackLight(uint8 light_level);
/****************************************************************************
* 名    称： SetBuzzer()
* 功    能： 蜂鸣器控制
* 入口参数： light_level
* 出口参数： 无
****************************************************************************/
void SetBuzzer(uint8 time);

/****************************************************************************
* 名    称： SetCommBps()
* 功    能： 设置通讯波特率
* 入口参数： Baud
* 出口参数： 无
****************************************************************************/
void SetCommBps(uint8 baudset);

/****************************************************************************
* 名    称： SetTouchScreen(uint8 cmd)
* 功    能： 触摸屏控制
* 入口参数： cmd   Bit0:1/0 触摸开/闭; Bit1 : 1/0 蜂鸣器开/闭; Bit2: 上传方式  
* 出口参数： 无
****************************************************************************/
void SetTouchScreen(uint8 cmd);

/****************************************************************************
* 名    称： SetTouchScreen_Adj()
* 功    能： 触摸屏校准，校准完毕后下发结束信息
* 入口参数： 无
* 出口参数： 无
****************************************************************************/
void SetTouchScreen_Adj(void);

/****************************************************************************
* 名    称： TestTouchScreen()
* 功    能： 触摸屏体验
* 入口参数： 无
* 出口参数： 无
****************************************************************************/
void TestTouchScreen(void);

/****************************************************************************
* 名    称： WriteLayer()
* 功    能： 写图层操作
* 入口参数： layer         写入的图层数
* 出口参数： 无
****************************************************************************/
void WriteLayer(uint8 layer);

/****************************************************************************
* 名    称： WriteLayer()
* 功    能： 切换图层显示
* 入口参数： layer         切换显示的图层
* 出口参数： 无
****************************************************************************/
void DisplyLayer(uint8 layer);


/****************************************************************************
* 名    称： SetScreen()
* 功    能： 切换画面
* 入口参数： screen_id，目标画面ID
* 出口参数： 无
****************************************************************************/
void SetScreen(uint16 screen_id);

/****************************************************************************
* 名    称： GetScreen()
* 功    能： 异步获取当前画面ID
* 入口参数： 无
* 出口参数： 无
****************************************************************************/
void GetScreen(void);

/****************************************************************************
* 名    称： GetControlValue()
* 功    能： 异步获取控件数值-HMI接收到获取数值命令之后返回控件数值，
             可以获取按钮、文本、进度条、滑动条、仪表控件的值
* 入口参数： screen_id，目标画面ID
* 入口参数： control_id，目标控件ID
* 出口参数： 无
****************************************************************************/
void GetControlValue(uint16 screen_id,uint16 control_id);

/****************************************************************************
* 名    称： SetButtonValue()
* 功    能： 设置按钮控件的状态值
* 入口参数： screen_id，目标画面ID
* 入口参数： control_id，目标控件ID
* 入口参数： value，按钮状态-0弹起，1按下
* 出口参数： 无
****************************************************************************/
void SetButtonValue(uint16 screen_id,uint16 control_id,uchar value);

/****************************************************************************
* 名    称： SetTextValue()
* 功    能： 设置文本控件的显示文字
* 入口参数： screen_id，目标画面ID
* 入口参数： control_id，目标控件ID
* 入口参数： str，显示文字
* 出口参数： 无
****************************************************************************/
void SetTextValue(uint16 screen_id,uint16 control_id,uchar *str);

/****************************************************************************
* 名    称： SetProgressValue()
* 功    能： 设置进度条控件的数值
* 入口参数： screen_id，控件所在的画面ID
* 入口参数： control_id，目标控件ID
* 入口参数： value_l-进度条的进度位置，低16位
* 入口参数： value_h-进度条的进度位置，高16位
* 出口参数： 无
****************************************************************************/
void SetProgressValue(uint16 screen_id,uint16 control_id,uint16 value_l,uint16 value_h);

/****************************************************************************
* 名    称： SetMeterValue()
* 功    能： 设置仪表控件的数值
* 入口参数： screen_id，控件所在的画面ID
* 入口参数： control_id，目标控件ID
* 入口参数： value_l-仪表指针位置，低16位
* 入口参数： value_h-仪表指针位置，高16位
* 出口参数： 无
****************************************************************************/
void SetMeterValue(uint16 screen_id,uint16 control_id,uint16 value_l,uint16 value_h);

/****************************************************************************
* 名    称： SetSliderValue()
* 功    能： 设置滑动条控件的数值
* 入口参数： screen_id，控件所在的画面ID
* 入口参数： control_id，目标控件ID
* 入口参数： value_l-滑动条的滑块位置，低16位
* 入口参数： value_h-滑动条的滑块位置，高16位
* 出口参数： 无
****************************************************************************/
void SetSliderValue(uint16 screen_id,uint16 control_id,uint16 value_l,uint16 value_h);
#endif
