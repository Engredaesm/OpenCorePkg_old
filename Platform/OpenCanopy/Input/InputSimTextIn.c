/** @file
  This file is part of OpenCanopy, OpenCore GUI.

  Copyright (c) 2018-2019, Download-Fritz. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-3-Clause
**/

#include <Uefi.h>

#include <Protocol/AppleKeyMapAggregator.h>

#include <Library/DebugLib.h>
#include <Library/OcAppleKeyMapLib.h>
#include <Library/OcBootManagementLib.h>
#include <Library/OcMiscLib.h>
#include <Library/UefiBootServicesTableLib.h>

#include "../GuiIo.h"

struct GUI_KEY_CONTEXT_ {
  OC_PICKER_CONTEXT                  *Context;
};

GUI_KEY_CONTEXT *
GuiKeyConstruct (
  IN OC_PICKER_CONTEXT  *PickerContext
  )
{
  STATIC GUI_KEY_CONTEXT  mContext;
  mContext.Context = PickerContext;

  return &mContext;
}

EFI_STATUS
EFIAPI
GuiKeyRead (
  IN OUT GUI_KEY_CONTEXT      *Context,
     OUT OC_PICKER_KEY_INFO   *PickerKeyInfo,
  IN     BOOLEAN              FilterForTyping
  )
{

  ASSERT (Context != NULL);
  ASSERT (PickerKeyInfo != NULL);

  Context->Context->HotKeyContext->GetKeyInfo (
    Context->Context,
    OC_PICKER_KEYS_FOR_PICKER,
    PickerKeyInfo
    );

  return EFI_SUCCESS;
}

VOID
EFIAPI
GuiKeyReset (
  IN OUT GUI_KEY_CONTEXT  *Context
  )
{
  ASSERT (Context != NULL);
  //
  // Flush console here?
  //
}

VOID
GuiKeyDestruct (
  IN GUI_KEY_CONTEXT  *Context
  )
{
  ASSERT (Context != NULL);
  ZeroMem (Context, sizeof (*Context));
}
