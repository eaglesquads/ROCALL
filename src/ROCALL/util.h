/*******************************************************************************
*
*  (C) COPYRIGHT AUTHORS, 2018 - 2019
*
*  TITLE:       UTIL.H
*
*  VERSION:     1.03
*
*  DATE:        07 Dec 2019
*
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
* ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
* TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
* PARTICULAR PURPOSE.
*
*******************************************************************************/

#pragma once

typedef struct _BL_ENTRY {
    LIST_ENTRY ListEntry;
    DWORD Hash;
} BL_ENTRY, *PBL_ENTRY;

typedef struct _BLACKLIST {
    HANDLE HeapHandle;
    ULONG NumberOfEntries;
    LIST_ENTRY ListHead;
} BLACKLIST, *PBLACKLIST;

#define CFG_FILE "blacklist.ini"

DWORD BlackListHashString(
    _In_ LPCSTR Name);

VOID OutputConsoleMessage(
    _In_ LPCSTR lpMessage);

BOOL BlackListCreateFromFile(
    _In_ BLACKLIST *BlackList,
    _In_ LPCSTR ConfigFileName,
    _In_ LPCSTR ConfigSectionName);

BOOL BlackListEntryPresent(
    _In_ BLACKLIST *BlackList,
    _In_ LPCSTR SyscallName);

VOID BlackListDestroy(
    _In_ BLACKLIST *BlackList);

BOOL IsReactOS(
    VOID);

BOOL GetReactOSVersion(
    _Out_ ULONG *MajorVersion,
    _Out_ ULONG *MinorVersion,
    _Out_ ULONG *Build,
    _Out_ ULONG *Revision);

BOOLEAN IsUserInAdminGroup();
BOOLEAN IsLocalSystem();
BOOLEAN IsRCHDrvLoaded();
BOOLEAN IsCheckedBuild();

BOOL GetCommandLineOption(
    _In_ LPCTSTR OptionName,
    _In_ BOOL IsParametric,
    _Out_writes_opt_z_(ValueSize) LPTSTR OptionValue,
    _In_ ULONG ValueSize);

VOID TryRunAsService(
    _In_ BOOLEAN IsRunAsLocalSystem,
    _In_ ROCALL_PARAMS *SessionParams);

PVOID QuerySystemInformationByClass(
    _In_ SYSTEM_INFORMATION_CLASS InfoClass);

VOID SessionParamsRemove();

VOID SessionParamsManage(
    _In_ BOOLEAN fSet,
    _Inout_ ROCALL_PARAMS *SessionParams);
