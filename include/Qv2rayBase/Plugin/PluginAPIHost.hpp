#pragma once
#include "Qv2rayBaseFeatures.hpp"
#include "QvPluginInterface.hpp"
#include "qv2raybase_export.h"

namespace Qv2rayBase::Plugins
{
    struct PluginInfo;
    class GuiPluginAPIHost;
    class PluginAPIHostPrivate;
    class QV2RAYBASE_EXPORT PluginAPIHost
    {
        friend class GuiPluginAPIHost;

      public:
        explicit PluginAPIHost();
        ~PluginAPIHost();

      public:
        // Kernel API
        std::unique_ptr<Qv2rayPlugin::Kernel::PluginKernel> Kernel_Create(const QUuid &kid) const;
        QString Kernel_GetName(const QUuid &kid) const;
        QUuid Kernel_QueryProtocol(const QString &protocol) const;

        // Event API
        template<typename E>
        void Event_Send(const typename E::EventObject &object) const
        {
            SendEventInternal(object);
        }

        // Outbound API
        std::optional<Qv2rayPlugin::Outbound::PluginOutboundDescriptor> Outbound_Deserialize(const QString &link) const;
        std::optional<QString> Outbound_Serialize(const Qv2rayPlugin::Outbound::PluginOutboundDescriptor &outbound) const;
        std::optional<Qv2rayPlugin::Outbound::PluginIOBoundData> Outbound_GetData(const QString &protocol, const QJsonObject &o) const;
        bool Outbound_SetData(const QString &protocol, QJsonObject &o, const Qv2rayPlugin::Outbound::PluginIOBoundData &info) const;

#if QV2RAYBASE_FEATURE(subscriptions)
        // Subscription Adapter API
        std::optional<std::shared_ptr<Qv2rayPlugin::subscription::SubscriptionDecoder>> Subscription_QueryType(const QString &type) const;
        QList<std::pair<const QvPluginInfo *, Qv2rayPlugin::subscription::SubscriptionInfoObject>> Subscription_GetAllAdapters() const;
#endif

      private:
        void SendEventInternal(const Qv2rayPlugin::Event::ConnectionStats::EventObject &) const;
        void SendEventInternal(const Qv2rayPlugin::Event::SystemProxy::EventObject &) const;
        void SendEventInternal(const Qv2rayPlugin::Event::Connectivity::EventObject &) const;
        void SendEventInternal(const Qv2rayPlugin::Event::ConnectionEntry::EventObject &) const;

      private:
        QScopedPointer<PluginAPIHostPrivate> d_ptr;
        Q_DECLARE_PRIVATE(PluginAPIHost)
    };

    const inline QStringList GetPluginComponentsString(const QList<Qv2rayPlugin::QV2RAY_PLUGIN_GUI_COMPONENT_TYPE> &types)
    {
        QStringList typesList;
        if (types.isEmpty())
            typesList << QObject::tr("None");
        for (const auto &type : types)
        {
            switch (type)
            {
                case Qv2rayPlugin::GUI_COMPONENT_SETTINGS: typesList << QObject::tr("Settings Widget"); break;
                case Qv2rayPlugin::GUI_COMPONENT_INBOUND_EDITOR: typesList << QObject::tr("Inbound Editor"); break;
                case Qv2rayPlugin::GUI_COMPONENT_OUTBOUND_EDITOR: typesList << QObject::tr("Outbound Editor"); break;
                case Qv2rayPlugin::GUI_COMPONENT_MAIN_WINDOW_ACTIONS: typesList << QObject::tr("MainWindow Actions"); break;
                case Qv2rayPlugin::GUI_COMPONENT_TRAY_MENUS: typesList << QObject::tr("Tray Menu"); break;
            }
        }
        return typesList;
    }

    const inline QStringList GetPluginComponentsString(const QList<Qv2rayPlugin::QV2RAY_PLUGIN_COMPONENT_TYPE> &types)
    {
        QStringList typesList;
        if (types.isEmpty())
            typesList << QObject::tr("None");
        for (const auto &type : types)
        {
            switch (type)
            {
                case Qv2rayPlugin::COMPONENT_KERNEL: typesList << QObject::tr("Kernel"); break;
                case Qv2rayPlugin::COMPONENT_OUTBOUND_HANDLER: typesList << QObject::tr("Outbound Handler/Parser"); break;
                case Qv2rayPlugin::COMPONENT_SUBSCRIPTION_ADAPTER: typesList << QObject::tr("Subscription Adapter"); break;
                case Qv2rayPlugin::COMPONENT_EVENT_HANDLER: typesList << QObject::tr("Event Handler"); break;
                case Qv2rayPlugin::COMPONENT_GUI: typesList << QObject::tr("GUI Components"); break;
            }
        }
        return typesList;
    }
} // namespace Qv2rayBase::Plugins