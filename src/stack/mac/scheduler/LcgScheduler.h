//
//                           SimuLTE
// Copyright (C) 2012 Antonio Virdis, Daniele Migliorini, Giovanni
// Accongiagioco, Generoso Pagano, Vincenzo Pii.
//
// This file is part of a software released under the license included in file
// "license.pdf". This license can be also found at http://www.ltesimulator.com/
// The above file and the present reference are part of the software itself,
// and cannot be removed from it.
//
// Author: sk0rp10
//

#ifndef _LTE_LCGSCHEDULER_H_
#define _LTE_LCGSCHEDULER_H_

#include "LteCommon.h"
#include "LteMacUe.h"

/// forward declarations
class LteSchedulerUeUl;
class LteMacPdu;
/**
 * @class LcgScheduler
 */
typedef std::map<MacCid, unsigned int> ScheduleList;

class LcgScheduler
{
    /**
     * Score-based schedulers descriptor.
     */
    template<typename T, typename S>
    struct SortedDesc
    {
        /// Connection identifier.
        T x_;
        /// Score value.
        S score_;

        /// Comparison operator to enable sorting.
        bool operator<(const SortedDesc& y) const
            {
            return score_ < y.score_;
        }

    public:
        SortedDesc(const T x, const S score)
        {
            x_ = x;
            score_ = score;
        }
    };

    struct StatusElem
    {
        unsigned int occupancy_;
        unsigned int bucket_;
        unsigned int sentData_;
        unsigned int sentSdus_;
    };

  protected:

    // last execution time
    simtime_t lastExecutionTime_;

    /// MAC module, used to get parameters from NED
    LteMacUe *mac_;

    /// Associated LteSchedulerUeUl (it is the one who creates the LteScheduler)
    LteSchedulerUeUl* ueScheduler_;

    // schedule List - returned by reference on scheduler invocation
    ScheduleList scheduleList_;

    /// Cid List
    typedef std::list<MacCid> CidList;

    // scheduling status map
    std::map<MacCid, StatusElem> statusMap_;

  public:

    /**
     * Default constructor.
     */
    LcgScheduler(LteMacUe * mac);

    /**
     * Destructor.
     */
    virtual ~LcgScheduler();

    /**
     * Initializes the LteScheduler.
     * @param ueScheduler UE scheduler
     */
    inline virtual void setUeUlScheduler(LteSchedulerUeUl* ueScheduler)
    {
        ueScheduler_ = ueScheduler;
    }

    /* Executes the LCG scheduling algorithm
     * @param availableBytes
     * @return # of scheduled sdus per cid
     */
    virtual ScheduleList& schedule(unsigned int availableBytes);

    // *****************************************************************************************

//        /// performs request of grant to the eNbScheduler
//        virtual unsigned int grant(MacCid cid,unsigned int bytes, bool& terminate,bool& active,bool& eligible);
//
//        /// calls eNbScheduler rtxschedule()
//        virtual bool rtxschedule();
//
//        virtual void notify( MacCid activeCid ) {;}
//
//        virtual void remove( MacCid cid ) {;}
//
//        virtual void update() {;}
};
#endif

