
#include "GfwWindowPortable.h"

void GfwPorting::GfwWindowPortable::setEventsHandler(GfwWindowEvents* eventHandler)
{
    m_evtWindow = eventHandler;
}

GfwPorting::GfwWindowPortable::GfwWindowPortable()
{
    m_evtWindow = nullptr;
}

GfwPorting::GfwWindowPortable::~GfwWindowPortable()
{
}
