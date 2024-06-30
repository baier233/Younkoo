param (
    [string]$projectDir
)

$commitHash = git rev-parse --short HEAD

$commitTime = git log -1 --format=%cd

$headerFilePath = "$projectDir\src\base\GitInfo.h"
$headerContent = @"
#pragma once
#define GIT_COMMIT_HASH "$commitHash"
#define GIT_COMMIT_TIME "$commitTime"
"@

Set-Content -Path $headerFilePath -Value $headerContent
