#ifndef SINK_INPUT_EFFECTS_HPP
#define SINK_INPUT_EFFECTS_HPP

#include "limiter.hpp"
#include "pipeline_base.hpp"
#include "pulse_manager.hpp"

class SinkInputEffects : public PipelineBase {
   public:
    SinkInputEffects(std::shared_ptr<PulseManager> pulse_manager);
    virtual ~SinkInputEffects();

    std::shared_ptr<PulseManager> pm;

   private:
    std::string log_tag = "sie: ";

    std::vector<GstInsertBin*> bins;
    std::unique_ptr<Limiter> limiter;

    void on_app_added(const std::shared_ptr<AppInfo>& app_info);
};

#endif
