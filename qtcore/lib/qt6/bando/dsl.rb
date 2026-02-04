# frozen_string_literal: true

module RubyQt6
  module Bando
    # @!visibility private
    def self.define_bando_qobject(qlass)
      unless qlass <= RubyQt6::QtCore::QObject
        raise "Invalid superclass: macro `define_bando_qobject` " \
          "only available for subclass of RubyQt6::QtCore::QObject"
      end

      define_bando_qlass(qlass) do
        {
          child_event: FunctionName::ChildEvent,
          timer_event: FunctionName::TimerEvent
        }.each do |meth, fn|
          define_method("_#{meth}") do |event|
            _ruby_value_handle_event(fn, event)
          end
        end
      end
    end

    # @!visibility private
    def self.define_bando_qwidget(qlass)
      unless qlass <= RubyQt6::QtWidgets::QWidget
        raise "Invalid superclass: macro `define_bando_qwidget` " \
          "only available for subclass of RubyQt6::QtWidgets::QWidget"
      end

      define_bando_qlass(qlass) do
        {
          child_event: FunctionName::ChildEvent,
          timer_event: FunctionName::TimerEvent,
          action_event: FunctionName::ActionEvent,
          change_event: FunctionName::ChangeEvent,
          close_event: FunctionName::CloseEvent,
          context_menu_event: FunctionName::ContextMenuEvent,
          drag_enter_event: FunctionName::DragEnterEvent,
          drag_leave_event: FunctionName::DragLeaveEvent,
          drag_move_event: FunctionName::DragMoveEvent,
          drop_event: FunctionName::DropEvent,
          enter_event: FunctionName::EnterEvent,
          focus_in_event: FunctionName::FocusInEvent,
          focus_out_event: FunctionName::FocusOutEvent,
          hide_event: FunctionName::HideEvent,
          input_method_event: FunctionName::InputMethodEvent,
          key_press_event: FunctionName::KeyPressEvent,
          key_release_event: FunctionName::KeyReleaseEvent,
          leave_event: FunctionName::LeaveEvent,
          mouse_double_click_event: FunctionName::MouseDoubleClickEvent,
          mouse_move_event: FunctionName::MouseMoveEvent,
          mouse_press_event: FunctionName::MousePressEvent,
          mouse_release_event: FunctionName::MouseReleaseEvent,
          move_event: FunctionName::MoveEvent,
          paint_event: FunctionName::PaintEvent,
          resize_event: FunctionName::ResizeEvent,
          show_event: FunctionName::ShowEvent,
          tablet_event: FunctionName::TabletEvent,
          wheel_event: FunctionName::WheelEvent
        }.each do |meth, fn|
          define_method("_#{meth}") do |event|
            _ruby_value_handle_event(fn, event)
          end
        end
      end
    end

    # @!visibility private
    def self.define_bando_qlass(qlass, &blk)
      qlass.class_eval do
        alias_method :_initialize, :initialize

        def initialize(*args)
          super
          _initialize_ruby_value(self, self.class._qmetaobject)
        end

        def self._qmetaobject
          superclass._qmetaobject
        end

        def self._rubyqt6_metaobject
          superclass._rubyqt6_metaobject
        end
      end
      qlass.class_eval(&blk)
    end
    private_class_method :define_bando_qlass
  end
end
