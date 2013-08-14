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

#ifndef _LTE_AMCPILOT_H_
#define _LTE_AMCPILOT_H_

//#include "LteCommon.h"
#include "LteAmc.h"
#include "UserTxParams.h"
#include "LteFeedback.h"

/// Forward declaration of LteAmc class, used by AmcPilot.
class LteAmc;

/**
 * @class AmcPilot
 * @brief Abstract AMC Pilot class
 *
 * This is the base class for all AMC pilots.
 * If you want to add a new AMC pilot, you have to subclass
 * from this class and to implement the computeTxParams method
 * according to your policy.
 */
class AmcPilot
{
  protected:

    //! LteAmc owner module
    LteAmc *amc_;

    //! Pilot Name
    std::string name_;

  public:

    /**
     * Constructor
     * @param amc LteAmc owner module
     */
    AmcPilot(LteAmc *amc)
    {
        amc_ = amc;
        name_ = "NONE";
    }

    /**
     * Assign logical bands for given nodeId and direction.
     * @param id The mobile node ID.
     * @param dir The link direction.
     * @return The user transmission parameters computed.
     */
    virtual const UserTxParams& computeTxParams(MacNodeId id, const Direction dir) = 0;

    /**
     * Function to get the AMC Pilot name.
     * Useful for debug print.
     */
    std::string getName()
    {
        return name_;
    }

    virtual void updateActiveUsers(ActiveSet aUser, Direction dir)=0;
};

#endif
