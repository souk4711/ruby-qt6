#include "qgraphicsitem-rb.hpp"
#include <qgraphicsitem.h>
#include <rice/qt6/qenum.hpp>

#include <QGraphicsEffect>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QPainter>
#include <QPen>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQGraphicsItem;
Class rb_cQAbstractGraphicsShapeItem;
Class rb_cQGraphicsEllipseItem;
Class rb_cQGraphicsPathItem;
Class rb_cQGraphicsPolygonItem;
Class rb_cQGraphicsRectItem;
Class rb_cQGraphicsSimpleTextItem;
Class rb_cQGraphicsItemGroup;
Class rb_cQGraphicsLineItem;
Class rb_cQGraphicsPixmapItem;

void Init_qgraphicsitem(Module rb_mQt6QtWidgets)
{
    rb_cQGraphicsItem =
        // RubyQt6::QtWidgets::QGraphicsItem
        define_class_under<QGraphicsItem>(rb_mQt6QtWidgets, "QGraphicsItem")
            // RubyQt6-Defined Functions
            .define_singleton_function("_delete_now", [](QGraphicsItem *item) -> void { delete item; }, Arg("item").takeOwnership())
            .define_singleton_function("_take_ownership_from_ruby", [](QGraphicsItem *) -> void {}, Arg("item").takeOwnership())
            // Public Functions
            .define_method("accept_drops", &QGraphicsItem::acceptDrops)
            .define_method("accept_hover_events", &QGraphicsItem::acceptHoverEvents)
            .define_method("accept_touch_events", &QGraphicsItem::acceptTouchEvents)
            .define_method("accepted_mouse_buttons", &QGraphicsItem::acceptedMouseButtons)
            .define_method("advance", &QGraphicsItem::advance, Arg("phase"))
            .define_method("bounding_rect", &QGraphicsItem::boundingRect)
            .define_method("bounding_region", &QGraphicsItem::boundingRegion, Arg("item_to_device_transform"))
            .define_method("bounding_region_granularity", &QGraphicsItem::boundingRegionGranularity)
            .define_method("cache_mode", &QGraphicsItem::cacheMode)
            .define_method("child_items", &QGraphicsItem::childItems)
            .define_method("children_bounding_rect", &QGraphicsItem::childrenBoundingRect)
            .define_method("clear_focus", &QGraphicsItem::clearFocus)
            .define_method("clip_path", &QGraphicsItem::clipPath)
            .define_method("collides_with_item", &QGraphicsItem::collidesWithItem, Arg("other"), Arg("mode") = static_cast<Qt::ItemSelectionMode>(Qt::IntersectsItemShape))
            .define_method("collides_with_path", &QGraphicsItem::collidesWithPath, Arg("path"), Arg("mode") = static_cast<Qt::ItemSelectionMode>(Qt::IntersectsItemShape))
            .define_method("colliding_items", &QGraphicsItem::collidingItems, Arg("mode") = static_cast<Qt::ItemSelectionMode>(Qt::IntersectsItemShape))
            .define_method("common_ancestor_item", &QGraphicsItem::commonAncestorItem, Arg("other"))
            .define_method("contains", &QGraphicsItem::contains, Arg("point"))
            .define_method("cursor", &QGraphicsItem::cursor)
            .define_method("data", &QGraphicsItem::data, Arg("key"))
            .define_method("device_transform", &QGraphicsItem::deviceTransform, Arg("viewport_transform"))
            .define_method("effective_opacity", &QGraphicsItem::effectiveOpacity)
            .define_method<void (QGraphicsItem::*)(const QRectF &, int, int)>("ensure_visible", &QGraphicsItem::ensureVisible, Arg("rect") = static_cast<const QRectF &>(QRectF()), Arg("xmargin") = static_cast<int>(50), Arg("ymargin") = static_cast<int>(50))
            .define_method<void (QGraphicsItem::*)(qreal, qreal, qreal, qreal, int, int)>("ensure_visible", &QGraphicsItem::ensureVisible, Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("xmargin") = static_cast<int>(50), Arg("ymargin") = static_cast<int>(50))
            .define_method("filters_child_events", &QGraphicsItem::filtersChildEvents)
            .define_method("flags", &QGraphicsItem::flags)
            .define_method("focus_item", &QGraphicsItem::focusItem)
            .define_method("focus_proxy", &QGraphicsItem::focusProxy)
            .define_method("focus_scope_item", &QGraphicsItem::focusScopeItem)
            .define_method("grab_keyboard", &QGraphicsItem::grabKeyboard)
            .define_method("grab_mouse", &QGraphicsItem::grabMouse)
            .define_method("graphics_effect", &QGraphicsItem::graphicsEffect)
            .define_method("group", &QGraphicsItem::group)
            .define_method("handles_child_events", &QGraphicsItem::handlesChildEvents)
            .define_method("has_cursor", &QGraphicsItem::hasCursor)
            .define_method("has_focus", &QGraphicsItem::hasFocus)
            .define_method("hide", &QGraphicsItem::hide)
            .define_method("input_method_hints", &QGraphicsItem::inputMethodHints)
            .define_method("install_scene_event_filter", &QGraphicsItem::installSceneEventFilter, Arg("filter_item"))
            .define_method("active?", &QGraphicsItem::isActive)
            .define_method("ancestor_of?", &QGraphicsItem::isAncestorOf, Arg("child"))
            .define_method("blocked_by_modal_panel?", &QGraphicsItem::isBlockedByModalPanel, Arg("blocking_panel") = static_cast<QGraphicsItem **>(nullptr))
            .define_method("clipped?", &QGraphicsItem::isClipped)
            .define_method("enabled?", &QGraphicsItem::isEnabled)
            .define_method<bool (QGraphicsItem::*)(const QRectF &) const>("obscured?", &QGraphicsItem::isObscured, Arg("rect") = static_cast<const QRectF &>(QRectF()))
            .define_method<bool (QGraphicsItem::*)(qreal, qreal, qreal, qreal) const>("obscured?", &QGraphicsItem::isObscured, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method("obscured_by?", &QGraphicsItem::isObscuredBy, Arg("item"))
            .define_method("panel?", &QGraphicsItem::isPanel)
            .define_method("selected?", &QGraphicsItem::isSelected)
            .define_method("under_mouse?", &QGraphicsItem::isUnderMouse)
            .define_method("visible?", &QGraphicsItem::isVisible)
            .define_method("visible_to?", &QGraphicsItem::isVisibleTo, Arg("parent"))
            .define_method("widget?", &QGraphicsItem::isWidget)
            .define_method("window?", &QGraphicsItem::isWindow)
            .define_method("item_transform", &QGraphicsItem::itemTransform, Arg("other"), Arg("ok") = static_cast<bool *>(nullptr))
            .define_method<QPainterPath (QGraphicsItem::*)(const QGraphicsItem *, const QPainterPath &) const>("map_from_item", &QGraphicsItem::mapFromItem, Arg("item"), Arg("path"))
            .define_method<QPointF (QGraphicsItem::*)(const QGraphicsItem *, const QPointF &) const>("map_from_item", &QGraphicsItem::mapFromItem, Arg("item"), Arg("point"))
            .define_method<QPointF (QGraphicsItem::*)(const QGraphicsItem *, qreal, qreal) const>("map_from_item", &QGraphicsItem::mapFromItem, Arg("item"), Arg("x"), Arg("y"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QGraphicsItem *, const QPolygonF &) const>("map_from_item", &QGraphicsItem::mapFromItem, Arg("item"), Arg("polygon"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QGraphicsItem *, const QRectF &) const>("map_from_item", &QGraphicsItem::mapFromItem, Arg("item"), Arg("rect"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QGraphicsItem *, qreal, qreal, qreal, qreal) const>("map_from_item", &QGraphicsItem::mapFromItem, Arg("item"), Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method<QPainterPath (QGraphicsItem::*)(const QPainterPath &) const>("map_from_parent", &QGraphicsItem::mapFromParent, Arg("path"))
            .define_method<QPointF (QGraphicsItem::*)(const QPointF &) const>("map_from_parent", &QGraphicsItem::mapFromParent, Arg("point"))
            .define_method<QPointF (QGraphicsItem::*)(qreal, qreal) const>("map_from_parent", &QGraphicsItem::mapFromParent, Arg("x"), Arg("y"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QPolygonF &) const>("map_from_parent", &QGraphicsItem::mapFromParent, Arg("polygon"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QRectF &) const>("map_from_parent", &QGraphicsItem::mapFromParent, Arg("rect"))
            .define_method<QPolygonF (QGraphicsItem::*)(qreal, qreal, qreal, qreal) const>("map_from_parent", &QGraphicsItem::mapFromParent, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method<QPainterPath (QGraphicsItem::*)(const QPainterPath &) const>("map_from_scene", &QGraphicsItem::mapFromScene, Arg("path"))
            .define_method<QPointF (QGraphicsItem::*)(const QPointF &) const>("map_from_scene", &QGraphicsItem::mapFromScene, Arg("point"))
            .define_method<QPointF (QGraphicsItem::*)(qreal, qreal) const>("map_from_scene", &QGraphicsItem::mapFromScene, Arg("x"), Arg("y"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QPolygonF &) const>("map_from_scene", &QGraphicsItem::mapFromScene, Arg("polygon"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QRectF &) const>("map_from_scene", &QGraphicsItem::mapFromScene, Arg("rect"))
            .define_method<QPolygonF (QGraphicsItem::*)(qreal, qreal, qreal, qreal) const>("map_from_scene", &QGraphicsItem::mapFromScene, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method<QRectF (QGraphicsItem::*)(const QGraphicsItem *, const QRectF &) const>("map_rect_from_item", &QGraphicsItem::mapRectFromItem, Arg("item"), Arg("rect"))
            .define_method<QRectF (QGraphicsItem::*)(const QGraphicsItem *, qreal, qreal, qreal, qreal) const>("map_rect_from_item", &QGraphicsItem::mapRectFromItem, Arg("item"), Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method<QRectF (QGraphicsItem::*)(const QRectF &) const>("map_rect_from_parent", &QGraphicsItem::mapRectFromParent, Arg("rect"))
            .define_method<QRectF (QGraphicsItem::*)(qreal, qreal, qreal, qreal) const>("map_rect_from_parent", &QGraphicsItem::mapRectFromParent, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method<QRectF (QGraphicsItem::*)(const QRectF &) const>("map_rect_from_scene", &QGraphicsItem::mapRectFromScene, Arg("rect"))
            .define_method<QRectF (QGraphicsItem::*)(qreal, qreal, qreal, qreal) const>("map_rect_from_scene", &QGraphicsItem::mapRectFromScene, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method<QRectF (QGraphicsItem::*)(const QGraphicsItem *, const QRectF &) const>("map_rect_to_item", &QGraphicsItem::mapRectToItem, Arg("item"), Arg("rect"))
            .define_method<QRectF (QGraphicsItem::*)(const QGraphicsItem *, qreal, qreal, qreal, qreal) const>("map_rect_to_item", &QGraphicsItem::mapRectToItem, Arg("item"), Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method<QRectF (QGraphicsItem::*)(const QRectF &) const>("map_rect_to_parent", &QGraphicsItem::mapRectToParent, Arg("rect"))
            .define_method<QRectF (QGraphicsItem::*)(qreal, qreal, qreal, qreal) const>("map_rect_to_parent", &QGraphicsItem::mapRectToParent, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method<QRectF (QGraphicsItem::*)(const QRectF &) const>("map_rect_to_scene", &QGraphicsItem::mapRectToScene, Arg("rect"))
            .define_method<QRectF (QGraphicsItem::*)(qreal, qreal, qreal, qreal) const>("map_rect_to_scene", &QGraphicsItem::mapRectToScene, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method<QPainterPath (QGraphicsItem::*)(const QGraphicsItem *, const QPainterPath &) const>("map_to_item", &QGraphicsItem::mapToItem, Arg("item"), Arg("path"))
            .define_method<QPointF (QGraphicsItem::*)(const QGraphicsItem *, const QPointF &) const>("map_to_item", &QGraphicsItem::mapToItem, Arg("item"), Arg("point"))
            .define_method<QPointF (QGraphicsItem::*)(const QGraphicsItem *, qreal, qreal) const>("map_to_item", &QGraphicsItem::mapToItem, Arg("item"), Arg("x"), Arg("y"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QGraphicsItem *, const QPolygonF &) const>("map_to_item", &QGraphicsItem::mapToItem, Arg("item"), Arg("polygon"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QGraphicsItem *, const QRectF &) const>("map_to_item", &QGraphicsItem::mapToItem, Arg("item"), Arg("rect"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QGraphicsItem *, qreal, qreal, qreal, qreal) const>("map_to_item", &QGraphicsItem::mapToItem, Arg("item"), Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method<QPainterPath (QGraphicsItem::*)(const QPainterPath &) const>("map_to_parent", &QGraphicsItem::mapToParent, Arg("path"))
            .define_method<QPointF (QGraphicsItem::*)(const QPointF &) const>("map_to_parent", &QGraphicsItem::mapToParent, Arg("point"))
            .define_method<QPointF (QGraphicsItem::*)(qreal, qreal) const>("map_to_parent", &QGraphicsItem::mapToParent, Arg("x"), Arg("y"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QPolygonF &) const>("map_to_parent", &QGraphicsItem::mapToParent, Arg("polygon"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QRectF &) const>("map_to_parent", &QGraphicsItem::mapToParent, Arg("rect"))
            .define_method<QPolygonF (QGraphicsItem::*)(qreal, qreal, qreal, qreal) const>("map_to_parent", &QGraphicsItem::mapToParent, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method<QPainterPath (QGraphicsItem::*)(const QPainterPath &) const>("map_to_scene", &QGraphicsItem::mapToScene, Arg("path"))
            .define_method<QPointF (QGraphicsItem::*)(const QPointF &) const>("map_to_scene", &QGraphicsItem::mapToScene, Arg("point"))
            .define_method<QPointF (QGraphicsItem::*)(qreal, qreal) const>("map_to_scene", &QGraphicsItem::mapToScene, Arg("x"), Arg("y"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QPolygonF &) const>("map_to_scene", &QGraphicsItem::mapToScene, Arg("polygon"))
            .define_method<QPolygonF (QGraphicsItem::*)(const QRectF &) const>("map_to_scene", &QGraphicsItem::mapToScene, Arg("rect"))
            .define_method<QPolygonF (QGraphicsItem::*)(qreal, qreal, qreal, qreal) const>("map_to_scene", &QGraphicsItem::mapToScene, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method("move_by", &QGraphicsItem::moveBy, Arg("dx"), Arg("dy"))
            .define_method("opacity", &QGraphicsItem::opacity)
            .define_method("opaque_area", &QGraphicsItem::opaqueArea)
            .define_method("paint", &QGraphicsItem::paint, Arg("painter"), Arg("option"), Arg("widget") = static_cast<QWidget *>(nullptr))
            .define_method("panel", &QGraphicsItem::panel)
            .define_method("panel_modality", &QGraphicsItem::panelModality)
            .define_method("parent_item", &QGraphicsItem::parentItem)
            .define_method("parent_object", &QGraphicsItem::parentObject)
            .define_method("parent_widget", &QGraphicsItem::parentWidget)
            .define_method("pos", &QGraphicsItem::pos)
            .define_method("remove_scene_event_filter", &QGraphicsItem::removeSceneEventFilter, Arg("filter_item"))
            .define_method("reset_transform", &QGraphicsItem::resetTransform)
            .define_method("rotation", &QGraphicsItem::rotation)
            .define_method("scale", &QGraphicsItem::scale)
            .define_method("scene", &QGraphicsItem::scene)
            .define_method("scene_bounding_rect", &QGraphicsItem::sceneBoundingRect)
            .define_method("scene_pos", &QGraphicsItem::scenePos)
            .define_method("scene_transform", &QGraphicsItem::sceneTransform)
            .define_method("scroll", &QGraphicsItem::scroll, Arg("dx"), Arg("dy"), Arg("rect") = static_cast<const QRectF &>(QRectF()))
            .define_method("set_accept_drops", &QGraphicsItem::setAcceptDrops, Arg("on"))
            .define_method("set_accept_hover_events", &QGraphicsItem::setAcceptHoverEvents, Arg("enabled"))
            .define_method("set_accept_touch_events", &QGraphicsItem::setAcceptTouchEvents, Arg("enabled"))
            .define_method("set_accepted_mouse_buttons", &QGraphicsItem::setAcceptedMouseButtons, Arg("buttons"))
            .define_method("set_active", &QGraphicsItem::setActive, Arg("active"))
            .define_method("set_bounding_region_granularity", &QGraphicsItem::setBoundingRegionGranularity, Arg("granularity"))
            .define_method("set_cache_mode", &QGraphicsItem::setCacheMode, Arg("mode"), Arg("cache_size") = static_cast<const QSize &>(QSize()))
            .define_method("set_cursor", &QGraphicsItem::setCursor, Arg("cursor"))
            .define_method("set_data", &QGraphicsItem::setData, Arg("key"), Arg("value"))
            .define_method("set_enabled", &QGraphicsItem::setEnabled, Arg("enabled"))
            .define_method("set_filters_child_events", &QGraphicsItem::setFiltersChildEvents, Arg("enabled"))
            .define_method("set_flag", &QGraphicsItem::setFlag, Arg("flag"), Arg("enabled") = static_cast<bool>(true))
            .define_method("set_flags", &QGraphicsItem::setFlags, Arg("flags"))
            .define_method("set_focus", &QGraphicsItem::setFocus, Arg("focus_reason") = static_cast<Qt::FocusReason>(Qt::OtherFocusReason))
            .define_method("set_focus_proxy", &QGraphicsItem::setFocusProxy, Arg("item"))
            .define_method("set_graphics_effect", &QGraphicsItem::setGraphicsEffect, Arg("effect"))
            .define_method("set_group", &QGraphicsItem::setGroup, Arg("group"))
            .define_method("set_handles_child_events", &QGraphicsItem::setHandlesChildEvents, Arg("enabled"))
            .define_method("set_input_method_hints", &QGraphicsItem::setInputMethodHints, Arg("hints"))
            .define_method("set_opacity", &QGraphicsItem::setOpacity, Arg("opacity"))
            .define_method("set_panel_modality", &QGraphicsItem::setPanelModality, Arg("panel_modality"))
            .define_method("set_parent_item", &QGraphicsItem::setParentItem, Arg("parent"))
            .define_method<void (QGraphicsItem::*)(const QPointF &)>("set_pos", &QGraphicsItem::setPos, Arg("pos"))
            .define_method<void (QGraphicsItem::*)(qreal, qreal)>("set_pos", &QGraphicsItem::setPos, Arg("x"), Arg("y"))
            .define_method("set_rotation", &QGraphicsItem::setRotation, Arg("angle"))
            .define_method("set_scale", &QGraphicsItem::setScale, Arg("scale"))
            .define_method("set_selected", &QGraphicsItem::setSelected, Arg("selected"))
            .define_method("set_tool_tip", &QGraphicsItem::setToolTip, Arg("tool_tip"))
            .define_method("set_transform", &QGraphicsItem::setTransform, Arg("matrix"), Arg("combine") = static_cast<bool>(false))
            .define_method<void (QGraphicsItem::*)(const QPointF &)>("set_transform_origin_point", &QGraphicsItem::setTransformOriginPoint, Arg("origin"))
            .define_method<void (QGraphicsItem::*)(qreal, qreal)>("set_transform_origin_point", &QGraphicsItem::setTransformOriginPoint, Arg("ax"), Arg("ay"))
            .define_method("set_transformations", &QGraphicsItem::setTransformations, Arg("transformations"))
            .define_method("set_visible", &QGraphicsItem::setVisible, Arg("visible"))
            .define_method("set_x", &QGraphicsItem::setX, Arg("x"))
            .define_method("set_y", &QGraphicsItem::setY, Arg("y"))
            .define_method("set_z_value", &QGraphicsItem::setZValue, Arg("z"))
            .define_method("shape", &QGraphicsItem::shape)
            .define_method("show", &QGraphicsItem::show)
            .define_method("stack_before", &QGraphicsItem::stackBefore, Arg("sibling"))
            .define_method<QGraphicsObject *(QGraphicsItem::*)()>("to_graphics_object", &QGraphicsItem::toGraphicsObject)
            .define_method<const QGraphicsObject *(QGraphicsItem::*)() const>("to_graphics_object", &QGraphicsItem::toGraphicsObject)
            .define_method("tool_tip", &QGraphicsItem::toolTip)
            .define_method("top_level_item", &QGraphicsItem::topLevelItem)
            .define_method("top_level_widget", &QGraphicsItem::topLevelWidget)
            .define_method("transform", &QGraphicsItem::transform)
            .define_method("transform_origin_point", &QGraphicsItem::transformOriginPoint)
            .define_method("transformations", &QGraphicsItem::transformations)
            .define_method("type", &QGraphicsItem::type)
            .define_method("ungrab_keyboard", &QGraphicsItem::ungrabKeyboard)
            .define_method("ungrab_mouse", &QGraphicsItem::ungrabMouse)
            .define_method("unset_cursor", &QGraphicsItem::unsetCursor)
            .define_method<void (QGraphicsItem::*)(const QRectF &)>("update", &QGraphicsItem::update, Arg("rect") = static_cast<const QRectF &>(QRectF()))
            .define_method<void (QGraphicsItem::*)(qreal, qreal, qreal, qreal)>("update", &QGraphicsItem::update, Arg("x"), Arg("y"), Arg("width"), Arg("height"))
            .define_method("window", &QGraphicsItem::window)
            .define_method("x", &QGraphicsItem::x)
            .define_method("y", &QGraphicsItem::y)
            .define_method("z_value", &QGraphicsItem::zValue);

    Data_Type<QGraphicsItem::GraphicsItemFlag> rb_cQGraphicsItemGraphicsItemFlag =
        // RubyQt6::QtWidgets::QGraphicsItem::GraphicsItemFlag
        define_qenum_under<QGraphicsItem::GraphicsItemFlag>(rb_cQGraphicsItem, "GraphicsItemFlag");
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemIsMovable", QGraphicsItem::GraphicsItemFlag::ItemIsMovable);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemIsSelectable", QGraphicsItem::GraphicsItemFlag::ItemIsSelectable);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemIsFocusable", QGraphicsItem::GraphicsItemFlag::ItemIsFocusable);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemClipsToShape", QGraphicsItem::GraphicsItemFlag::ItemClipsToShape);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemClipsChildrenToShape", QGraphicsItem::GraphicsItemFlag::ItemClipsChildrenToShape);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemIgnoresTransformations", QGraphicsItem::GraphicsItemFlag::ItemIgnoresTransformations);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemIgnoresParentOpacity", QGraphicsItem::GraphicsItemFlag::ItemIgnoresParentOpacity);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemDoesntPropagateOpacityToChildren", QGraphicsItem::GraphicsItemFlag::ItemDoesntPropagateOpacityToChildren);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemStacksBehindParent", QGraphicsItem::GraphicsItemFlag::ItemStacksBehindParent);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemUsesExtendedStyleOption", QGraphicsItem::GraphicsItemFlag::ItemUsesExtendedStyleOption);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemHasNoContents", QGraphicsItem::GraphicsItemFlag::ItemHasNoContents);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemSendsGeometryChanges", QGraphicsItem::GraphicsItemFlag::ItemSendsGeometryChanges);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemAcceptsInputMethod", QGraphicsItem::GraphicsItemFlag::ItemAcceptsInputMethod);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemNegativeZStacksBehindParent", QGraphicsItem::GraphicsItemFlag::ItemNegativeZStacksBehindParent);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemIsPanel", QGraphicsItem::GraphicsItemFlag::ItemIsPanel);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemIsFocusScope", QGraphicsItem::GraphicsItemFlag::ItemIsFocusScope);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemSendsScenePositionChanges", QGraphicsItem::GraphicsItemFlag::ItemSendsScenePositionChanges);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemStopsClickFocusPropagation", QGraphicsItem::GraphicsItemFlag::ItemStopsClickFocusPropagation);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemStopsFocusHandling", QGraphicsItem::GraphicsItemFlag::ItemStopsFocusHandling);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemFlag, "ItemContainsChildrenInShape", QGraphicsItem::GraphicsItemFlag::ItemContainsChildrenInShape);

    Data_Type<QGraphicsItem::GraphicsItemChange> rb_cQGraphicsItemGraphicsItemChange =
        // RubyQt6::QtWidgets::QGraphicsItem::GraphicsItemChange
        define_qenum_under<QGraphicsItem::GraphicsItemChange>(rb_cQGraphicsItem, "GraphicsItemChange");
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemPositionChange", QGraphicsItem::GraphicsItemChange::ItemPositionChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemVisibleChange", QGraphicsItem::GraphicsItemChange::ItemVisibleChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemEnabledChange", QGraphicsItem::GraphicsItemChange::ItemEnabledChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemSelectedChange", QGraphicsItem::GraphicsItemChange::ItemSelectedChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemParentChange", QGraphicsItem::GraphicsItemChange::ItemParentChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemChildAddedChange", QGraphicsItem::GraphicsItemChange::ItemChildAddedChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemChildRemovedChange", QGraphicsItem::GraphicsItemChange::ItemChildRemovedChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemTransformChange", QGraphicsItem::GraphicsItemChange::ItemTransformChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemPositionHasChanged", QGraphicsItem::GraphicsItemChange::ItemPositionHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemTransformHasChanged", QGraphicsItem::GraphicsItemChange::ItemTransformHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemSceneChange", QGraphicsItem::GraphicsItemChange::ItemSceneChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemVisibleHasChanged", QGraphicsItem::GraphicsItemChange::ItemVisibleHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemEnabledHasChanged", QGraphicsItem::GraphicsItemChange::ItemEnabledHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemSelectedHasChanged", QGraphicsItem::GraphicsItemChange::ItemSelectedHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemParentHasChanged", QGraphicsItem::GraphicsItemChange::ItemParentHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemSceneHasChanged", QGraphicsItem::GraphicsItemChange::ItemSceneHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemCursorChange", QGraphicsItem::GraphicsItemChange::ItemCursorChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemCursorHasChanged", QGraphicsItem::GraphicsItemChange::ItemCursorHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemToolTipChange", QGraphicsItem::GraphicsItemChange::ItemToolTipChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemToolTipHasChanged", QGraphicsItem::GraphicsItemChange::ItemToolTipHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemFlagsChange", QGraphicsItem::GraphicsItemChange::ItemFlagsChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemFlagsHaveChanged", QGraphicsItem::GraphicsItemChange::ItemFlagsHaveChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemZValueChange", QGraphicsItem::GraphicsItemChange::ItemZValueChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemZValueHasChanged", QGraphicsItem::GraphicsItemChange::ItemZValueHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemOpacityChange", QGraphicsItem::GraphicsItemChange::ItemOpacityChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemOpacityHasChanged", QGraphicsItem::GraphicsItemChange::ItemOpacityHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemScenePositionHasChanged", QGraphicsItem::GraphicsItemChange::ItemScenePositionHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemRotationChange", QGraphicsItem::GraphicsItemChange::ItemRotationChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemRotationHasChanged", QGraphicsItem::GraphicsItemChange::ItemRotationHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemScaleChange", QGraphicsItem::GraphicsItemChange::ItemScaleChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemScaleHasChanged", QGraphicsItem::GraphicsItemChange::ItemScaleHasChanged);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemTransformOriginPointChange", QGraphicsItem::GraphicsItemChange::ItemTransformOriginPointChange);
        define_qenum_value_under(rb_cQGraphicsItemGraphicsItemChange, "ItemTransformOriginPointHasChanged", QGraphicsItem::GraphicsItemChange::ItemTransformOriginPointHasChanged);

    Data_Type<QGraphicsItem::CacheMode> rb_cQGraphicsItemCacheMode =
        // RubyQt6::QtWidgets::QGraphicsItem::CacheMode
        define_qenum_under<QGraphicsItem::CacheMode>(rb_cQGraphicsItem, "CacheMode");
        define_qenum_value_under(rb_cQGraphicsItemCacheMode, "NoCache", QGraphicsItem::CacheMode::NoCache);
        define_qenum_value_under(rb_cQGraphicsItemCacheMode, "ItemCoordinateCache", QGraphicsItem::CacheMode::ItemCoordinateCache);
        define_qenum_value_under(rb_cQGraphicsItemCacheMode, "DeviceCoordinateCache", QGraphicsItem::CacheMode::DeviceCoordinateCache);

    Data_Type<QGraphicsItem::PanelModality> rb_cQGraphicsItemPanelModality =
        // RubyQt6::QtWidgets::QGraphicsItem::PanelModality
        define_qenum_under<QGraphicsItem::PanelModality>(rb_cQGraphicsItem, "PanelModality");
        define_qenum_value_under(rb_cQGraphicsItemPanelModality, "NonModal", QGraphicsItem::PanelModality::NonModal);
        define_qenum_value_under(rb_cQGraphicsItemPanelModality, "PanelModal", QGraphicsItem::PanelModality::PanelModal);
        define_qenum_value_under(rb_cQGraphicsItemPanelModality, "SceneModal", QGraphicsItem::PanelModality::SceneModal);

    rb_cQAbstractGraphicsShapeItem =
        // RubyQt6::QtWidgets::QAbstractGraphicsShapeItem
        define_class_under<QAbstractGraphicsShapeItem, QGraphicsItem>(rb_mQt6QtWidgets, "QAbstractGraphicsShapeItem")
            // Public Functions
            .define_method("brush", &QAbstractGraphicsShapeItem::brush)
            .define_method("pen", &QAbstractGraphicsShapeItem::pen)
            .define_method("set_brush", &QAbstractGraphicsShapeItem::setBrush, Arg("brush"))
            .define_method("set_pen", &QAbstractGraphicsShapeItem::setPen, Arg("pen"));

    rb_cQGraphicsEllipseItem =
        // RubyQt6::QtWidgets::QGraphicsEllipseItem
        define_class_under<QGraphicsEllipseItem, QAbstractGraphicsShapeItem>(rb_mQt6QtWidgets, "QGraphicsEllipseItem")
            // Constructor
            .define_constructor(Constructor<QGraphicsEllipseItem, QGraphicsItem *>(), Arg("parent"))
            // Public Functions
            .define_method("rect", &QGraphicsEllipseItem::rect)
            .define_method<void (QGraphicsEllipseItem::*)(const QRectF &)>("set_rect", &QGraphicsEllipseItem::setRect, Arg("rect"))
            .define_method<void (QGraphicsEllipseItem::*)(qreal, qreal, qreal, qreal)>("set_rect", &QGraphicsEllipseItem::setRect, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method("set_span_angle", &QGraphicsEllipseItem::setSpanAngle, Arg("angle"))
            .define_method("set_start_angle", &QGraphicsEllipseItem::setStartAngle, Arg("angle"))
            .define_method("start_angle", &QGraphicsEllipseItem::startAngle)
            .define_method("span_angle", &QGraphicsEllipseItem::spanAngle);

    rb_cQGraphicsPathItem =
        // RubyQt6::QtWidgets::QGraphicsPathItem
        define_class_under<QGraphicsPathItem, QAbstractGraphicsShapeItem>(rb_mQt6QtWidgets, "QGraphicsPathItem")
            // Constructor
            .define_constructor(Constructor<QGraphicsPathItem, QGraphicsItem *>(), Arg("parent"))
            // Public Functions
            .define_method("path", &QGraphicsPathItem::path)
            .define_method("set_path", &QGraphicsPathItem::setPath, Arg("path"));

    rb_cQGraphicsPolygonItem =
        // RubyQt6::QtWidgets::QGraphicsPolygonItem
        define_class_under<QGraphicsPolygonItem, QAbstractGraphicsShapeItem>(rb_mQt6QtWidgets, "QGraphicsPolygonItem")
            // Constructor
            .define_constructor(Constructor<QGraphicsPolygonItem, QGraphicsItem *>(), Arg("parent"))
            // Public Functions
            .define_method("fill_rule", &QGraphicsPolygonItem::fillRule)
            .define_method("polygon", &QGraphicsPolygonItem::polygon)
            .define_method("set_fill_rule", &QGraphicsPolygonItem::setFillRule, Arg("rule"))
            .define_method("set_polygon", &QGraphicsPolygonItem::setPolygon, Arg("polygon"));

    rb_cQGraphicsRectItem =
        // RubyQt6::QtWidgets::QGraphicsRectItem
        define_class_under<QGraphicsRectItem, QAbstractGraphicsShapeItem>(rb_mQt6QtWidgets, "QGraphicsRectItem")
            // Constructor
            .define_constructor(Constructor<QGraphicsRectItem, QGraphicsItem *>(), Arg("parent"))
            // Public Functions
            .define_method("rect", &QGraphicsRectItem::rect)
            .define_method<void (QGraphicsRectItem::*)(const QRectF &)>("set_rect", &QGraphicsRectItem::setRect, Arg("rect"))
            .define_method<void (QGraphicsRectItem::*)(qreal, qreal, qreal, qreal)>("set_rect", &QGraphicsRectItem::setRect, Arg("x"), Arg("y"), Arg("w"), Arg("h"));

    rb_cQGraphicsSimpleTextItem =
        // RubyQt6::QtWidgets::QGraphicsSimpleTextItem
        define_class_under<QGraphicsSimpleTextItem, QAbstractGraphicsShapeItem>(rb_mQt6QtWidgets, "QGraphicsSimpleTextItem")
            // Constructor
            .define_constructor(Constructor<QGraphicsSimpleTextItem, QGraphicsItem *>(), Arg("parent"))
            // Public Functions
            .define_method("font", &QGraphicsSimpleTextItem::font)
            .define_method("set_font", &QGraphicsSimpleTextItem::setFont, Arg("font"))
            .define_method("set_text", &QGraphicsSimpleTextItem::setText, Arg("text"))
            .define_method("text", &QGraphicsSimpleTextItem::text);

    rb_cQGraphicsItemGroup =
        // RubyQt6::QtWidgets::QGraphicsItemGroup
        define_class_under<QGraphicsItemGroup, QGraphicsItem>(rb_mQt6QtWidgets, "QGraphicsItemGroup")
            // Constructor
            .define_constructor(Constructor<QGraphicsItemGroup, QGraphicsItem *>(), Arg("parent"))
            // Public Functions
            .define_method("add_to_group", &QGraphicsItemGroup::addToGroup, Arg("item"))
            .define_method("remove_from_group", &QGraphicsItemGroup::removeFromGroup, Arg("item"));

    rb_cQGraphicsLineItem =
        // RubyQt6::QtWidgets::QGraphicsLineItem
        define_class_under<QGraphicsLineItem, QGraphicsItem>(rb_mQt6QtWidgets, "QGraphicsLineItem")
            // Constructor
            .define_constructor(Constructor<QGraphicsLineItem, QGraphicsItem *>(), Arg("parent"))
            // Public Functions
            .define_method("line", &QGraphicsLineItem::line)
            .define_method("pen", &QGraphicsLineItem::pen)
            .define_method<void (QGraphicsLineItem::*)(const QLineF &)>("set_line", &QGraphicsLineItem::setLine, Arg("line"))
            .define_method<void (QGraphicsLineItem::*)(qreal, qreal, qreal, qreal)>("set_line", &QGraphicsLineItem::setLine, Arg("x1"), Arg("y1"), Arg("x2"), Arg("y2"))
            .define_method("set_pen", &QGraphicsLineItem::setPen, Arg("pen"));

    rb_cQGraphicsPixmapItem =
        // RubyQt6::QtWidgets::QGraphicsPixmapItem
        define_class_under<QGraphicsPixmapItem, QGraphicsItem>(rb_mQt6QtWidgets, "QGraphicsPixmapItem")
            // Constructor
            .define_constructor(Constructor<QGraphicsPixmapItem, QGraphicsItem *>(), Arg("parent"))
            // Public Functions
            .define_method("offset", &QGraphicsPixmapItem::offset)
            .define_method("pixmap", &QGraphicsPixmapItem::pixmap)
            .define_method<void (QGraphicsPixmapItem::*)(const QPointF &)>("set_offset", &QGraphicsPixmapItem::setOffset, Arg("offset"))
            .define_method<void (QGraphicsPixmapItem::*)(qreal, qreal)>("set_offset", &QGraphicsPixmapItem::setOffset, Arg("x"), Arg("y"))
            .define_method("set_pixmap", &QGraphicsPixmapItem::setPixmap, Arg("pixmap"))
            .define_method("set_shape_mode", &QGraphicsPixmapItem::setShapeMode, Arg("mode"))
            .define_method("set_transformation_mode", &QGraphicsPixmapItem::setTransformationMode, Arg("mode"))
            .define_method("shape_mode", &QGraphicsPixmapItem::shapeMode)
            .define_method("transformation_mode", &QGraphicsPixmapItem::transformationMode);

    Data_Type<QGraphicsPixmapItem::ShapeMode> rb_cQGraphicsPixmapItemShapeMode =
        // RubyQt6::QtWidgets::QGraphicsPixmapItem::ShapeMode
        define_qenum_under<QGraphicsPixmapItem::ShapeMode>(rb_cQGraphicsPixmapItem, "ShapeMode");
        define_qenum_value_under(rb_cQGraphicsPixmapItemShapeMode, "MaskShape", QGraphicsPixmapItem::ShapeMode::MaskShape);
        define_qenum_value_under(rb_cQGraphicsPixmapItemShapeMode, "BoundingRectShape", QGraphicsPixmapItem::ShapeMode::BoundingRectShape);
        define_qenum_value_under(rb_cQGraphicsPixmapItemShapeMode, "HeuristicMaskShape", QGraphicsPixmapItem::ShapeMode::HeuristicMaskShape);
}
