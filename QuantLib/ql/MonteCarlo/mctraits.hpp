/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2000, 2001, 2002, 2003 RiskMap srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/reference/license.html>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file mctraits.hpp
    \brief Monte Carlo policies
*/

#ifndef quantlib_mc_traits_hpp
#define quantlib_mc_traits_hpp

#include <ql/MonteCarlo/pathgenerator.hpp>
#include <ql/MonteCarlo/multipathgenerator.hpp>
#include <ql/MonteCarlo/pathpricer.hpp>
#include <ql/RandomNumbers/rngtraits.hpp>

namespace QuantLib {

    // path generation and pricing traits

    //! default Monte Carlo traits for single-variate models
    template <class rng_traits = PseudoRandom>
    struct SingleVariate {
        typedef Path path_type;
        typedef PathPricer<path_type> path_pricer_type;
        typedef typename rng_traits::rsg_type rsg_type;
        typedef PathGenerator<rsg_type> path_generator_type;
    };

    #ifndef QL_DISABLE_DEPRECATED
    /*! \deprecated use SingleVariate instead */
    template <class rng_traits = PseudoRandom>
    struct SingleAsset {
        typedef typename SingleVariate<rng_traits>::path_type path_type;
        typedef typename SingleVariate<rng_traits>::path_pricer_type
                                                             path_pricer_type;
        typedef typename SingleVariate<rng_traits>::rsg_type rsg_type;
        typedef typename SingleVariate<rng_traits>::path_generator_type
                                                          path_generator_type;
    };
    #endif

    //! default Monte Carlo traits for multi-variate models
    template <class rng_traits = PseudoRandom>
    struct MultiVariate {
        typedef MultiPath path_type;
        typedef PathPricer<path_type> path_pricer_type;
        typedef typename rng_traits::rsg_type rsg_type;
        typedef MultiPathGenerator<rsg_type> path_generator_type;
    };

    #ifndef QL_DISABLE_DEPRECATED
    /*! \deprecated use MultiVariate instead */
    template <class rng_traits = PseudoRandom>
    struct MultiAsset {
        typedef typename MultiVariate<rng_traits>::path_type path_type;
        typedef typename MultiVariate<rng_traits>::path_pricer_type
                                                             path_pricer_type;
        typedef typename MultiVariate<rng_traits>::rsg_type rsg_type;
        typedef typename MultiVariate<rng_traits>::path_generator_type
                                                          path_generator_type;
    };
    #endif

}


#endif
