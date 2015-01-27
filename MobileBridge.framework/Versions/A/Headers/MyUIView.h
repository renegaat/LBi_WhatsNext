//
//  MyUIView.h
//  template
//
//  Created by Lior Lavon on 12/16/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MyUIView : UIView
{
    int objectPositionInJson;
}
@property (nonatomic) int objectPositionInJson;

-(int)getPos;

@end
