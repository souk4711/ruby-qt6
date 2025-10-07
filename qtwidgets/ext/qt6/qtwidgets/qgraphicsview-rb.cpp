#include "qgraphicsview-rb.hpp"
#include <qgraphicsview.h>

#include <QGraphicsItem>

using namespace Rice;

Rice::Class rb_cQGraphicsView;

void Init_qgraphicsview(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQGraphicsView =
        // RubyQt6::QtWidgets::QGraphicsView
        define_class_under<QGraphicsView, QAbstractScrollArea>(rb_mQt6QtWidgets, "QGraphicsView")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QGraphicsView::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QGraphicsView, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("alignment", &QGraphicsView::alignment)
            .define_method("background_brush", &QGraphicsView::backgroundBrush)
            .define_method("cache_mode", &QGraphicsView::cacheMode)
            .define_method<void (QGraphicsView::*)(const QGraphicsItem *)>("center_on", &QGraphicsView::centerOn, Arg("item"))
            .define_method<void (QGraphicsView::*)(const QPointF &)>("center_on", &QGraphicsView::centerOn, Arg("pos"))
            .define_method<void (QGraphicsView::*)(qreal, qreal)>("center_on", &QGraphicsView::centerOn, Arg("x"), Arg("y"))
            .define_method("drag_mode", &QGraphicsView::dragMode)
            .define_method<void (QGraphicsView::*)(const QGraphicsItem *, int, int)>("ensure_visible", &QGraphicsView::ensureVisible, Arg("item"), Arg("xmargin") = static_cast<int>(50), Arg("ymargin") = static_cast<int>(50))
            .define_method<void (QGraphicsView::*)(const QRectF &, int, int)>("ensure_visible", &QGraphicsView::ensureVisible, Arg("rect"), Arg("xmargin") = static_cast<int>(50), Arg("ymargin") = static_cast<int>(50))
            .define_method<void (QGraphicsView::*)(qreal, qreal, qreal, qreal, int, int)>("ensure_visible", &QGraphicsView::ensureVisible, Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("xmargin") = static_cast<int>(50), Arg("ymargin") = static_cast<int>(50))
            .define_method<void (QGraphicsView::*)(const QGraphicsItem *, Qt::AspectRatioMode)>("fit_in_view", &QGraphicsView::fitInView, Arg("item"), Arg("aspect_radio_mode") = static_cast<Qt::AspectRatioMode>(Qt::IgnoreAspectRatio))
            .define_method<void (QGraphicsView::*)(const QRectF &, Qt::AspectRatioMode)>("fit_in_view", &QGraphicsView::fitInView, Arg("rect"), Arg("aspect_radio_mode") = static_cast<Qt::AspectRatioMode>(Qt::IgnoreAspectRatio))
            .define_method<void (QGraphicsView::*)(qreal, qreal, qreal, qreal, Qt::AspectRatioMode)>("fit_in_view", &QGraphicsView::fitInView, Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("aspect_radio_mode") = static_cast<Qt::AspectRatioMode>(Qt::IgnoreAspectRatio))
            .define_method("foreground_brush", &QGraphicsView::foregroundBrush)
            .define_method("interactive?", &QGraphicsView::isInteractive)
            .define_method("transformed?", &QGraphicsView::isTransformed)
            .define_method<QGraphicsItem *(QGraphicsView::*)(const QPoint &) const>("item_at", &QGraphicsView::itemAt, Arg("pos"))
            .define_method<QGraphicsItem *(QGraphicsView::*)(int, int) const>("item_at", &QGraphicsView::itemAt, Arg("x"), Arg("y"))
            .define_method<QList<QGraphicsItem *> (QGraphicsView::*)() const>("items", &QGraphicsView::items)
            .define_method<QList<QGraphicsItem *> (QGraphicsView::*)(const QPainterPath &, Qt::ItemSelectionMode) const>("items", &QGraphicsView::items, Arg("path"), Arg("mode") = static_cast<Qt::ItemSelectionMode>(Qt::IntersectsItemShape))
            .define_method<QList<QGraphicsItem *> (QGraphicsView::*)(const QPoint &) const>("items", &QGraphicsView::items, Arg("pos"))
            .define_method<QList<QGraphicsItem *> (QGraphicsView::*)(const QPolygon &, Qt::ItemSelectionMode) const>("items", &QGraphicsView::items, Arg("polygon"), Arg("mode") = static_cast<Qt::ItemSelectionMode>(Qt::IntersectsItemShape))
            .define_method<QList<QGraphicsItem *> (QGraphicsView::*)(const QRect &, Qt::ItemSelectionMode) const>("items", &QGraphicsView::items, Arg("rect"), Arg("mode") = static_cast<Qt::ItemSelectionMode>(Qt::IntersectsItemShape))
            .define_method<QList<QGraphicsItem *> (QGraphicsView::*)(int, int) const>("items", &QGraphicsView::items, Arg("x"), Arg("y"))
            .define_method<QList<QGraphicsItem *> (QGraphicsView::*)(int, int, int, int, Qt::ItemSelectionMode) const>("items", &QGraphicsView::items, Arg("x"), Arg("y"), Arg("w"), Arg("h"), Arg("mode") = static_cast<Qt::ItemSelectionMode>(Qt::IntersectsItemShape))
            .define_method<QPainterPath (QGraphicsView::*)(const QPainterPath &) const>("map_from_scene", &QGraphicsView::mapFromScene, Arg("path"))
            .define_method<QPoint (QGraphicsView::*)(const QPointF &) const>("map_from_scene", &QGraphicsView::mapFromScene, Arg("point"))
            .define_method<QPoint (QGraphicsView::*)(qreal, qreal) const>("map_from_scene", &QGraphicsView::mapFromScene, Arg("x"), Arg("y"))
            .define_method<QPolygon (QGraphicsView::*)(const QPolygonF &) const>("map_from_scene", &QGraphicsView::mapFromScene, Arg("polygon"))
            .define_method<QPolygon (QGraphicsView::*)(const QRectF &) const>("map_from_scene", &QGraphicsView::mapFromScene, Arg("rect"))
            .define_method<QPolygon (QGraphicsView::*)(qreal, qreal, qreal, qreal) const>("map_from_scene", &QGraphicsView::mapFromScene, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method<QPainterPath (QGraphicsView::*)(const QPainterPath &) const>("map_to_scene", &QGraphicsView::mapToScene, Arg("path"))
            .define_method<QPointF (QGraphicsView::*)(const QPoint &) const>("map_to_scene", &QGraphicsView::mapToScene, Arg("point"))
            .define_method<QPointF (QGraphicsView::*)(int, int) const>("map_to_scene", &QGraphicsView::mapToScene, Arg("x"), Arg("y"))
            .define_method<QPolygonF (QGraphicsView::*)(const QPolygon &) const>("map_to_scene", &QGraphicsView::mapToScene, Arg("polygon"))
            .define_method<QPolygonF (QGraphicsView::*)(const QRect &) const>("map_to_scene", &QGraphicsView::mapToScene, Arg("rect"))
            .define_method<QPolygonF (QGraphicsView::*)(int, int, int, int) const>("map_to_scene", &QGraphicsView::mapToScene, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method("optimization_flags", &QGraphicsView::optimizationFlags)
            .define_method("render", &QGraphicsView::render, Arg("painter"), Arg("target") = static_cast<const QRectF &>(QRectF()), Arg("source") = static_cast<const QRect &>(QRect()), Arg("aspect_ratio_mode") = static_cast<Qt::AspectRatioMode>(Qt::KeepAspectRatio))
            .define_method("render_hints", &QGraphicsView::renderHints)
            .define_method("reset_cached_content", &QGraphicsView::resetCachedContent)
            .define_method("reset_transform", &QGraphicsView::resetTransform)
            .define_method("resize_anchor", &QGraphicsView::resizeAnchor)
            .define_method("rotate", &QGraphicsView::rotate, Arg("angle"))
            .define_method("rubber_band_rect", &QGraphicsView::rubberBandRect)
            .define_method("rubber_band_selection_mode", &QGraphicsView::rubberBandSelectionMode)
            .define_method("scale", &QGraphicsView::scale, Arg("sx"), Arg("sy"))
            .define_method("scene", &QGraphicsView::scene)
            .define_method("scene_rect", &QGraphicsView::sceneRect)
            .define_method("set_alignment", &QGraphicsView::setAlignment, Arg("alignment"))
            .define_method("set_background_brush", &QGraphicsView::setBackgroundBrush, Arg("brush"))
            .define_method("set_cache_mode", &QGraphicsView::setCacheMode, Arg("mode"))
            .define_method("set_drag_mode", &QGraphicsView::setDragMode, Arg("mode"))
            .define_method("set_foreground_brush", &QGraphicsView::setForegroundBrush, Arg("brush"))
            .define_method("set_interactive", &QGraphicsView::setInteractive, Arg("allowed"))
            .define_method("set_optimization_flag", &QGraphicsView::setOptimizationFlag, Arg("flag"), Arg("enabled") = static_cast<bool>(true))
            .define_method("set_optimization_flags", &QGraphicsView::setOptimizationFlags, Arg("flags"))
            .define_method("set_render_hint", &QGraphicsView::setRenderHint, Arg("hint"), Arg("enabled") = static_cast<bool>(true))
            .define_method("set_render_hints", &QGraphicsView::setRenderHints, Arg("hints"))
            .define_method("set_resize_anchor", &QGraphicsView::setResizeAnchor, Arg("anchor"))
            .define_method("set_rubber_band_selection_mode", &QGraphicsView::setRubberBandSelectionMode, Arg("mode"))
            .define_method("set_scene", &QGraphicsView::setScene, Arg("scene"))
            .define_method<void (QGraphicsView::*)(const QRectF &)>("set_scene_rect", &QGraphicsView::setSceneRect, Arg("rect"))
            .define_method<void (QGraphicsView::*)(qreal, qreal, qreal, qreal)>("set_scene_rect", &QGraphicsView::setSceneRect, Arg("x"), Arg("y"), Arg("w"), Arg("h"))
            .define_method("set_transform", &QGraphicsView::setTransform, Arg("matrix"), Arg("combine") = static_cast<bool>(false))
            .define_method("set_transformation_anchor", &QGraphicsView::setTransformationAnchor, Arg("anchor"))
            .define_method("set_viewport_update_mode", &QGraphicsView::setViewportUpdateMode, Arg("mode"))
            .define_method("shear", &QGraphicsView::shear, Arg("sh"), Arg("sv"))
            .define_method("transform", &QGraphicsView::transform)
            .define_method("transformation_anchor", &QGraphicsView::transformationAnchor)
            .define_method("translate", &QGraphicsView::translate, Arg("dx"), Arg("dy"))
            .define_method("viewport_transform", &QGraphicsView::viewportTransform)
            .define_method("viewport_update_mode", &QGraphicsView::viewportUpdateMode)
            // Public Slots
            .define_method("invalidate_scene", &QGraphicsView::invalidateScene, Arg("rect") = static_cast<const QRectF &>(QRectF()), Arg("layers") = static_cast<QGraphicsScene::SceneLayers>(QGraphicsScene::AllLayers))
            .define_method("update_scene", &QGraphicsView::updateScene, Arg("rects"))
            .define_method("update_scene_rect", &QGraphicsView::updateSceneRect, Arg("rect"))
            // Signals
            .define_method("rubber_band_changed", &QGraphicsView::rubberBandChanged, Arg("viewport_rect"), Arg("from_scene_point"), Arg("to_scene_point"));

    Enum<QGraphicsView::CacheModeFlag> rb_cQGraphicsViewCacheModeFlag =
        // RubyQt6::QtWidgets::QGraphicsView::CacheModeFlag
        define_enum_under<QGraphicsView::CacheModeFlag>("CacheModeFlag", rb_cQGraphicsView)
            .define_value("CacheNone", QGraphicsView::CacheModeFlag::CacheNone)
            .define_value("CacheBackground", QGraphicsView::CacheModeFlag::CacheBackground);

    Enum<QGraphicsView::DragMode> rb_cQGraphicsViewDragMode =
        // RubyQt6::QtWidgets::QGraphicsView::DragMode
        define_enum_under<QGraphicsView::DragMode>("DragMode", rb_cQGraphicsView)
            .define_value("NoDrag", QGraphicsView::DragMode::NoDrag)
            .define_value("ScrollHandDrag", QGraphicsView::DragMode::ScrollHandDrag)
            .define_value("RubberBandDrag", QGraphicsView::DragMode::RubberBandDrag);

    Enum<QGraphicsView::OptimizationFlag> rb_cQGraphicsViewOptimizationFlag =
        // RubyQt6::QtWidgets::QGraphicsView::OptimizationFlag
        define_enum_under<QGraphicsView::OptimizationFlag>("OptimizationFlag", rb_cQGraphicsView)
            .define_value("DontSavePainterState", QGraphicsView::OptimizationFlag::DontSavePainterState)
            .define_value("DontAdjustForAntialiasing", QGraphicsView::OptimizationFlag::DontAdjustForAntialiasing)
            .define_value("IndirectPainting", QGraphicsView::OptimizationFlag::IndirectPainting);

    Enum<QGraphicsView::ViewportAnchor> rb_cQGraphicsViewViewportAnchor =
        // RubyQt6::QtWidgets::QGraphicsView::ViewportAnchor
        define_enum_under<QGraphicsView::ViewportAnchor>("ViewportAnchor", rb_cQGraphicsView)
            .define_value("NoAnchor", QGraphicsView::ViewportAnchor::NoAnchor)
            .define_value("AnchorViewCenter", QGraphicsView::ViewportAnchor::AnchorViewCenter)
            .define_value("AnchorUnderMouse", QGraphicsView::ViewportAnchor::AnchorUnderMouse);

    Enum<QGraphicsView::ViewportUpdateMode> rb_cQGraphicsViewViewportUpdateMode =
        // RubyQt6::QtWidgets::QGraphicsView::ViewportUpdateMode
        define_enum_under<QGraphicsView::ViewportUpdateMode>("ViewportUpdateMode", rb_cQGraphicsView)
            .define_value("FullViewportUpdate", QGraphicsView::ViewportUpdateMode::FullViewportUpdate)
            .define_value("MinimalViewportUpdate", QGraphicsView::ViewportUpdateMode::MinimalViewportUpdate)
            .define_value("SmartViewportUpdate", QGraphicsView::ViewportUpdateMode::SmartViewportUpdate)
            .define_value("NoViewportUpdate", QGraphicsView::ViewportUpdateMode::NoViewportUpdate)
            .define_value("BoundingRectViewportUpdate", QGraphicsView::ViewportUpdateMode::BoundingRectViewportUpdate);
}
