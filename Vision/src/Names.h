/* 
 * The contents of this file are subject to the Mozilla Public 
 * License Version 1.1 (the "License"); you may not use this file 
 * except in compliance with the License. You may obtain a copy of 
 * the License at http://www.mozilla.org/MPL/ 
 * 
 * Software distributed under the License is distributed on an "AS 
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or 
 * implied. See the License for the specific language governing 
 * rights and limitations under the License. 
 * 
 * The Original Code is Vision. 
 * 
 * The Initial Developer of the Original Code is The Vision Team.
 * Portions created by The Vision Team are
 * Copyright (C) 1999, 2000, 2001 The Vision Team.  All Rights
 * Reserved.
 * 
 * Contributor(s): Wade Majors <guru@startrek.com>
 *                 Rene Gollent
 *                 Todd Lair
 *                 Andrew Bazan
 *                 Jamie Wilkinson
 */
 
#ifndef _NAMES_H_
#define _NAMES_H_

#include <ListItem.h>
#include <ListView.h>
#include <String.h>

class BPopUpMenu;

class NameItem : public BListItem
{
	public:

										NameItem (
											const char *,
											int32);
	virtual							~NameItem (void);
	BString							Name (void) const;
	BString							Address (void) const;
	int32								Status (void) const;

	void								SetName (const char *);
	void								SetAddress (const char *);
	void								SetStatus (int32);

	virtual void					DrawItem (BView *father, BRect frame,
										bool complete = false);

	private:

	BString							myName,
										myAddress;
	int32								myStatus;
};

class NamesView : public BListView
{
	public:

										NamesView (BRect frame);
	virtual							~NamesView (void);
	virtual void					AttachedToWindow (void);
	virtual void					MouseDown(BPoint myPoint);

	void								SetColor (int32, rgb_color);
	rgb_color						GetColor (int32) const;
	void								SetFont (int32, const BFont *);
	void							ClearList (void);
	
	private:

	BPopUpMenu						*myPopUp;
	BMenu 							*CTCPPopUp;
	int32								lastSelected;
	int32								lastButton;

	rgb_color						opColor,
										voiceColor,
										textColor,
										ignoreColor,
										bgColor;
};

const uint32 POPUP_MODE								= 'pumo';
const uint32 POPUP_CTCP								= 'puct';
const uint32 POPUP_WHOIS							= 'puwh';
const uint32 POPUP_KICK								= 'puki';

#endif
