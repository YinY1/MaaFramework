#pragma once

#include <functional>
#include <ostream>
#include <unordered_map>

#include <meojson/json.hpp>

#include "MaaConf.h"

MAA_NS_BEGIN

enum class MaaMsg : int64_t
{
    InvalidMsg = 0,
    ResourceMsg = 10000,

    ResourceStartLoading = 11000,
    ResourceLoadingCompleted = 12000,
    ResourceLoadingError = 13000,

    ControllerMsg = 20000,
    InstanceMsg = 30000,

    /*  TaskMsg = 100000,    */
    TaskStarted = 110000,
    TaskCompleted = 120000,
    TaskFailed = 130000,
    TaskStopped = 140000,

    PipelineMsg = 1000000,
};

inline std::ostream& operator<<(std::ostream& os, const MaaMsg& type)
{
    static const std::unordered_map<MaaMsg, std::string> _type_name = {
        /* Global Msg */
        { MaaMsg::InvalidMsg, "InvalidMsg" },

        /* Resrouce Msg */
        { MaaMsg::ResourceMsg, "ResourceMsg" },
        { MaaMsg::ResourceStartLoading, "ResourceStartLoading" },
        { MaaMsg::ResourceLoadingCompleted, "ResourceLoadingCompleted" },
        { MaaMsg::ResourceLoadingError, "ResourceLoadingError" },

        /* Controller Msg */
        { MaaMsg::ControllerMsg, "ControllerMsg" },

        /* Instance Msg */
        { MaaMsg::InstanceMsg, "InstanceMsg" },

        //{ MaaMsg::TaskMsg, "TaskMsg" },
        { MaaMsg::TaskStarted, "TaskStarted" },
        { MaaMsg::TaskCompleted, "TaskCompleted" },
        { MaaMsg::TaskFailed, "TaskFailed" },
        { MaaMsg::TaskStopped, "TaskStopped" },

        { MaaMsg::PipelineMsg, "PipelineMsg" },
    };
    return os << _type_name.at(type);
}

// 内部使用的回调
class InstanceMgr;
using MaaInstCallback = std::function<void(MaaMsg msg, const json::value& details, InstanceMgr* inst)>;

MAA_NS_END
