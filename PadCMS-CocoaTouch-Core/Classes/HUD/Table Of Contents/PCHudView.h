//
//  PCHUDView.h
//  Pad CMS
//
//  Created by Maxim Pervushin on 7/16/12.
//  Copyright (c) PadCMS (http://www.padcms.net)
//
//
//  This software is governed by the CeCILL-C  license under French law and
//  abiding by the rules of distribution of free software.  You can  use,
//  modify and/ or redistribute the software under the terms of the CeCILL-C
//  license as circulated by CEA, CNRS and INRIA at the following URL
//  "http://www.cecill.info".
//  
//  As a counterpart to the access to the source code and  rights to copy,
//  modify and redistribute granted by the license, users are provided only
//  with a limited warranty  and the software's author,  the holder of the
//  economic rights,  and the successive licensors  have only  limited
//  liability.
//  
//  In this respect, the user's attention is drawn to the risks associated
//  with loading,  using,  modifying and/or developing or reproducing the
//  software by the user in light of its specific status of free software,
//  that may mean  that it is complicated to manipulate,  and  that  also
//  therefore means  that it is reserved for developers  and  experienced
//  professionals having in-depth computer knowledge. Users are therefore
//  encouraged to load and test the software's suitability as regards their
//  requirements in conditions enabling the security of their systems and/or
//  data to be ensured and,  more generally, to use and operate it in the
//  same conditions as regards security.
//  
//  The fact that you are presently reading this means that you have had
//  knowledge of the CeCILL-C license and that you accept its terms.
//

#import <UIKit/UIKit.h>

#import "PCGridView.h"
#import "PCTocView.h"

@class PCHudView;
@class PCTopBarView;

/**
 @brief PCHUDView actions delegation protocol.
 */ 
@protocol PCHudViewDelegate <NSObject>

@optional
/**
 @brief Tells the delegate to perform action with data that corresponds index.
 @param hudView - PCHUDView instance requesting this information.
 @param index - index of selected cell.
 */ 
 - (void)hudView:(PCHudView *)hudView didSelectIndex:(NSUInteger)index;

@optional

- (void)hudView:(PCHudView *)hudView willTransitToc:(PCTocView *)tocView toState:(PCTocViewState)state;

@optional

- (void)hudView:(PCHudView *)hudView didTransitToc:(PCTocView *)tocView toState:(PCTocViewState)state;

@end


/**
 @brief PCHUDView data provider protocol. 
 */ 
@protocol PCHudViewDataSource <NSObject>

/**
 @brief Asks the data source to return cell size for tocView in hudView.
 @param hudView - PCHUDView instance requesting this information.
 @param tocView - PCGridView instance to set cell size.
 @result the size for cells in grid view.
 */ 
- (CGSize)hudView:(PCHudView *)hudView itemSizeInTOC:(PCGridView *)tocView;

/**
 @brief Asks the data source for image for given index.
 @param hudView - the PCHUDView object requesting this information.
 @result table of contents image.
 */ 
- (UIImage *)hudView:(PCHudView *)hudView tocImageForIndex:(NSUInteger)index;

/**
 @brief Asks the data source for image for given index.
 @param hudView - the PCHUDView object requesting this information.
 @result the number of table of content items.
 */ 
- (NSUInteger)hudViewTOCItemsCount:(PCHudView *)hudView;

@end 


/**
 @brief PCGridView cell for displaying table of contents element.
 */ 
@interface PCHudView : UIView <MFGridViewDelegate, MFGridViewDataSource, PCTocViewDelegate>

/**
 @brief The object that acts as the delegate of the receiving HUD view.
 */ 
@property (assign, nonatomic) id<PCHudViewDelegate> delegate;

/**
 @brief The object that acts as the data source of the receiving HUD view.
 */ 
@property (assign, nonatomic) id<PCHudViewDataSource> dataSource;

@property (readonly) PCTopBarView *topBarView;

/**
 @brief Grid view object used to display table of contents items at the top of the HUD view.
 */ 
@property (readonly) PCTocView *topTocView;

/**
 @brief Grid view object used to display table of contents items at the bottom of the HUD view.
 */ 
@property (readonly) PCTocView *bottomTocView;

/**
 @brief reloads data of the receiver.
 */ 
- (void)reloadData;

@end
