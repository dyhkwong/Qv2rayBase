//  Qv2rayBase, the modular feature-rich infrastructure library for Qv2ray.
//  Copyright (C) 2021 Moody and relavent Qv2ray contributors.
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Common/CommonTypes.hpp"
#include "Qv2rayBaseLibrary.hpp"

namespace Qv2rayBase::Interfaces
{
    class IConfigurationGenerator
    {
      public:
        IConfigurationGenerator() = default;
        virtual ~IConfigurationGenerator() = default;

        virtual ProfileContent ApplyRouting(const ProfileContent &profile, const RoutingObject &route) = 0;

        //        void SaveRoutes() const;
        //        //
        //        std::tuple<bool, DNSConfig, FakeDNSConfig> GetDNSSettings(const GroupRoutingId &id) const
        //        {
        //            return { configs[id].overrideDNS, configs[id].dnsConfig, configs[id].fakeDNSConfig };
        //        }
        //        std::pair<bool, RouteConfig> GetAdvancedRoutingSettings(const GroupRoutingId &id) const
        //        {
        //            return { configs[id].overrideRoute, configs[id].routeConfig };
        //        }
        //        //
        //        bool SetDNSSettings(const GroupRoutingId &id, bool overrideGlobal, const DNSConfig &dns, const FakeDNSConfig &fakeDNS);
        //        bool SetAdvancedRouteSettings(const GroupRoutingId &id, bool overrideGlobal, const RouteConfig &dns);
        //        //
        //        OUTBOUNDS ExpandExternalConnection(const OUTBOUNDS &outbounds) const;
        //        //
        //        // Final Config Generation
        //        ProfileContent GenerateFinalConfig(const ConnectionGroupPair &pair, bool hasAPI = true) const;
        //        ProfileContent GenerateFinalConfig(ProfileContent root, const GroupRoutingId &routingId, bool hasAPI = true) const;
        //        //
        //        bool ExpandChainedOutbounds(ProfileContent &) const;
        //      private:
        //        QHash<GroupRoutingId, GroupRoutingConfig> configs;
    };
} // namespace Qv2rayBase::Profile