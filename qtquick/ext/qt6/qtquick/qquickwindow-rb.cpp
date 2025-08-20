#include "qquickwindow-rb.hpp"
#include <QQuickGraphicsConfiguration>
#include <QQuickGraphicsDevice>
#include <QQuickItem>
#include <QQuickRenderControl>
#include <QQuickRenderTarget>
#include <QQuickWindow>
#include <QSGImageNode>
#include <QSGNinePatchNode>
#include <QSGRectangleNode>
#include <QSGTextNode>
#include <QSGTexture>
#include <QtCore/QRunnable>
#include <QtQml/QQmlIncubationController>

using namespace Rice;

Rice::Class rb_cQQuickWindow;
Rice::Class rb_cQQuickWindowGraphicsStateInfo;

void Init_QQuickWindow(Rice::Module rb_mQt6QtQuick)
{
    rb_cQQuickWindow =
        // Qt6::QtQuick::QQuickWindow
        define_class_under<QQuickWindow, QWindow>(rb_mQt6QtQuick, "QQuickWindow")
            // Public Functions
            .define_constructor(Constructor<QQuickWindow, QQuickRenderControl *>(), Arg("render_control"))
            .define_constructor(Constructor<QQuickWindow, QWindow *>(), Arg("parent") = static_cast<QWindow *>(nullptr))
            .define_method("active_focus_item_changed", &QQuickWindow::activeFocusItemChanged)
            .define_method("begin_external_commands", &QQuickWindow::beginExternalCommands)
            // TODO: .define_method("closing", &QQuickWindow::closing, Arg("close"))
            .define_method("color", &QQuickWindow::color)
            .define_method("content_item", &QQuickWindow::contentItem)
            .define_method("create_image_node", &QQuickWindow::createImageNode)
            .define_method("create_nine_patch_node", &QQuickWindow::createNinePatchNode)
            .define_method("create_rectangle_node", &QQuickWindow::createRectangleNode)
            .define_method("create_text_node", &QQuickWindow::createTextNode)
            // TODO: .define_method<QSGTexture *(QQuickWindow::*)(const QImage &) const>("create_texture_from_image", &QQuickWindow::createTextureFromImage, Arg("image"))
            // TODO: .define_method<QSGTexture *(QQuickWindow::*)(const QImage &, QQuickWindow::CreateTextureOptions) const>("create_texture_from_image", &QQuickWindow::createTextureFromImage, Arg("image"), Arg("options"))
            // TODO: .define_method("create_texture_from_rhi_texture", &QQuickWindow::createTextureFromRhiTexture, Arg("texture"), Arg("options") = static_cast<CreateTextureOptions>({}))
            .define_method("effective_device_pixel_ratio", &QQuickWindow::effectiveDevicePixelRatio)
            .define_method("end_external_commands", &QQuickWindow::endExternalCommands)
            .define_method("focus_object", &QQuickWindow::focusObject)
            .define_method("grab_window", &QQuickWindow::grabWindow)
            .define_method("graphics_configuration", &QQuickWindow::graphicsConfiguration)
            .define_method("graphics_device", &QQuickWindow::graphicsDevice)
            .define_method("graphics_state_info", &QQuickWindow::graphicsStateInfo)
            .define_method("incubation_controller", &QQuickWindow::incubationController)
            .define_method("is_persistent_graphics", &QQuickWindow::isPersistentGraphics)
            .define_method("is_persistent_scene_graph", &QQuickWindow::isPersistentSceneGraph)
            .define_method("is_scene_graph_initialized", &QQuickWindow::isSceneGraphInitialized)
            .define_method("palette_changed", &QQuickWindow::paletteChanged)
            .define_method("palette_created", &QQuickWindow::paletteCreated)
            .define_method("renderer_interface", &QQuickWindow::rendererInterface)
            .define_method("render_target", &QQuickWindow::renderTarget)
            // TODO: .define_method("rhi", &QQuickWindow::rhi)
            .define_method("schedule_render_job", &QQuickWindow::scheduleRenderJob, Arg("job"), Arg("schedule"))
            .define_method("set_color", &QQuickWindow::setColor, Arg("color"))
            .define_method("set_graphics_configuration", &QQuickWindow::setGraphicsConfiguration, Arg("config"))
            .define_method("set_graphics_device", &QQuickWindow::setGraphicsDevice, Arg("device"))
            .define_method("set_persistent_graphics", &QQuickWindow::setPersistentGraphics, Arg("persistent"))
            .define_method("set_persistent_scene_graph", &QQuickWindow::setPersistentSceneGraph, Arg("persistent"))
            .define_method("set_render_target", &QQuickWindow::setRenderTarget, Arg("target"))
            // TODO: .define_method("swap_chain", &QQuickWindow::swapChain)
            // Reimplemented Public Functions
            .define_method("accessible_root", &QQuickWindow::accessibleRoot)
            // Public Slots
            .define_method("release_resources", &QQuickWindow::releaseResources)
            .define_method("update", &QQuickWindow::update)
            // Signals
            .define_method("active_focus_item", &QQuickWindow::activeFocusItem)
            .define_method("after_animating", &QQuickWindow::afterAnimating)
            .define_method("after_frame_end", &QQuickWindow::afterFrameEnd)
            .define_method("after_render_pass_recording", &QQuickWindow::afterRenderPassRecording)
            .define_method("after_rendering", &QQuickWindow::afterRendering)
            .define_method("after_synchronizing", &QQuickWindow::afterSynchronizing)
            .define_method("before_frame_begin", &QQuickWindow::beforeFrameBegin)
            .define_method("before_render_pass_recording", &QQuickWindow::beforeRenderPassRecording)
            .define_method("before_rendering", &QQuickWindow::beforeRendering)
            .define_method("before_synchronizing", &QQuickWindow::beforeSynchronizing)
            .define_method("color_changed", &QQuickWindow::colorChanged, Arg(""))
            .define_method("frame_swapped", &QQuickWindow::frameSwapped)
            .define_method("scene_graph_about_to_stop", &QQuickWindow::sceneGraphAboutToStop)
            .define_method("scene_graph_error", &QQuickWindow::sceneGraphError, Arg("error"), Arg("message"))
            .define_method("scene_graph_initialized", &QQuickWindow::sceneGraphInitialized)
            .define_method("scene_graph_invalidated", &QQuickWindow::sceneGraphInvalidated)
            // Static Public Members
            .define_singleton_function("graphics_api", &QQuickWindow::graphicsApi)
            .define_singleton_function("has_default_alpha_buffer", &QQuickWindow::hasDefaultAlphaBuffer)
            .define_singleton_function("scene_graph_backend", &QQuickWindow::sceneGraphBackend)
            .define_singleton_function("set_default_alpha_buffer", &QQuickWindow::setDefaultAlphaBuffer, Arg("use_alpha"))
            .define_singleton_function("set_graphics_api", &QQuickWindow::setGraphicsApi, Arg("api"))
            .define_singleton_function("set_scene_graph_backend", &QQuickWindow::setSceneGraphBackend, Arg("backend"))
            .define_singleton_function("set_text_render_type", &QQuickWindow::setTextRenderType, Arg("render_type"))
            .define_singleton_function("text_render_type", &QQuickWindow::textRenderType);

    // clang-format off
    rb_cQQuickWindowGraphicsStateInfo =
        // Qt6::QtQuick::QQuickWindow::GraphicsStateInfo
        define_class_under<QQuickWindow::GraphicsStateInfo>(rb_cQQuickWindow, "GraphicsStateInfo")
            .define_constructor(Constructor<QQuickWindow::GraphicsStateInfo>())
            .define_attr("current_frame_slot", &QQuickWindow::GraphicsStateInfo::currentFrameSlot)
            .define_attr("frames_in_flight", &QQuickWindow::GraphicsStateInfo::framesInFlight);

    Enum<QQuickWindow::CreateTextureOption> rb_cQQuickWindowCreateTextureOption =
        // Qt6::QtQuick::QQuickWindow::CreateTextureOption
        define_enum_under<QQuickWindow::CreateTextureOption>("CreateTextureOption", rb_cQQuickWindow)
            .define_value("TextureHasAlphaChannel", QQuickWindow::CreateTextureOption::TextureHasAlphaChannel)
            .define_value("TextureHasMipmaps", QQuickWindow::CreateTextureOption::TextureHasMipmaps)
            .define_value("TextureOwnsGLTexture", QQuickWindow::CreateTextureOption::TextureOwnsGLTexture)
            .define_value("TextureCanUseAtlas", QQuickWindow::CreateTextureOption::TextureCanUseAtlas)
            .define_value("TextureIsOpaque", QQuickWindow::CreateTextureOption::TextureIsOpaque);

    Enum<QQuickWindow::RenderStage> rb_cQQuickWindowRenderStage =
        // Qt6::QtQuick::QQuickWindow::RenderStage
        define_enum_under<QQuickWindow::RenderStage>("RenderStage", rb_cQQuickWindow)
            .define_value("BeforeSynchronizingStage", QQuickWindow::RenderStage::BeforeSynchronizingStage)
            .define_value("AfterSynchronizingStage", QQuickWindow::RenderStage::AfterSynchronizingStage)
            .define_value("BeforeRenderingStage", QQuickWindow::RenderStage::BeforeRenderingStage)
            .define_value("AfterRenderingStage", QQuickWindow::RenderStage::AfterRenderingStage)
            .define_value("AfterSwapStage", QQuickWindow::RenderStage::AfterSwapStage)
            .define_value("NoStage", QQuickWindow::RenderStage::NoStage);

    Enum<QQuickWindow::SceneGraphError> rb_cQQuickWindowSceneGraphError =
        // Qt6::QtQuick::QQuickWindow::SceneGraphError
        define_enum_under<QQuickWindow::SceneGraphError>("SceneGraphError", rb_cQQuickWindow)
            .define_value("ContextNotAvailable", QQuickWindow::SceneGraphError::ContextNotAvailable);

    Enum<QQuickWindow::TextRenderType> rb_cQQuickWindowTextRenderType =
        // Qt6::QtQuick::QQuickWindow::TextRenderType
        define_enum_under<QQuickWindow::TextRenderType>("TextRenderType", rb_cQQuickWindow)
            .define_value("QtTextRendering", QQuickWindow::TextRenderType::QtTextRendering)
            .define_value("NativeTextRendering", QQuickWindow::TextRenderType::NativeTextRendering)
            .define_value("CurveTextRendering", QQuickWindow::TextRenderType::CurveTextRendering);
}
