/**
 * Module: TCAnchorToolbarView
 *
 * Function: 工具栏
 */

#import <UIKit/UIKit.h>
#import "TCMsgModel.h"
#import "TCMsgListCell.h"
#import "V8HorizontalPickerView.h"
#import <TCBeautyPanel/TCBeautyPanel.h>

@protocol TCAnchorToolbarDelegate <NSObject>
- (void)closeRTMP;
- (void)closeVC;
- (void)clickScreen:(UITapGestureRecognizer *)gestureRecognizer;
- (void)clickCamera:(UIButton *)button;
- (void)clickBeauty:(UIButton *)button;
- (void)clickMusic:(UIButton *)button;
- (void)clickTorch:(UIButton *)button;
- (void)clickLog:(UIButton *)button;
- (void)clickMusicSelect:(UIButton *)button;
- (void)clickMusicClose:(UIButton *)button;
- (void)clickVolumeSwitch:(UIButton *)button;
- (void)sliderValueChange:(UISlider *)slider;
- (void)sliderValueChangeEx:(UISlider *)slider;
- (void)selectEffect:(NSInteger)index;
- (void)selectEffect2:(NSInteger)index;
- (void)motionTmplSelected:(NSString *)mid;
- (void)greenSelected:(NSURL *)mid;
- (void)filterSelected:(int)index;
@end

/**
 *  推流模块逻辑view，里面展示了消息列表，弹幕动画，观众列表，美颜，美白等UI，其中与SDK的逻辑交互需要交给主控制器处理。
 */
@interface TCAnchorToolbarView : UIView <
    UITextFieldDelegate,
    V8HorizontalPickerViewDelegate,
    V8HorizontalPickerViewDataSource >

@property (nonatomic, weak)    id<TCAnchorToolbarDelegate> delegate;

@property (nonatomic, retain) UIButton   *btnChat;
@property (nonatomic, retain) UIButton   *btnCamera;
@property (nonatomic, retain) UIButton   *btnBeauty;
@property (nonatomic, retain) UIButton   *btnLog;
@property (nonatomic, retain) UIButton   *btnTorch;
@property (nonatomic, retain) UIButton   *btnMusic;
@property (nonatomic, retain) UIView     *cover;
@property (nonatomic, retain) TCBeautyPanel *vBeauty;
@property (nonatomic, retain) UIView     *vMusicPanel;

- (void)setButtonHidden:(BOOL)buttonHidden;
- (void)setLiveInfo:(TCRoomInfo *)liveInfo;

- (void)closeVCWithError:(NSString *)msg Alert:(BOOL)isAlert Result:(BOOL)isShowResult;

- (void)enableMix:(BOOL)enable;

- (void)handleIMMessage:(IMUserAble*)info msgText:(NSString*)msgText;

- (void)triggeValue;

@end


@interface TCPushShowResultView : UIView

typedef void (^ShowResultComplete)(void);

- (instancetype)initWithFrame:(CGRect)frame resultData:(TCShowLiveTopView *)resultData backHomepage:(ShowResultComplete)backHomepage;

@end
