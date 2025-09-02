# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qcoreapplication.html
    class QCoreApplication < RubyQt6::QtCore::QObject
      # @return [QString]
      #
      # This property holds the name of this application.
      #
      # The application name is used in various Qt classes and modules, most
      # prominently in QSettings when it is constructed using the default
      # constructor. Other uses are in formatted logging output (see
      # qSetMessagePattern()), in output by QCommandLineParser, in
      # QTemporaryDir and QTemporaryFile default paths, and in some file
      # locations of QStandardPaths. Qt D-Bus, Accessibility, and the XCB
      # platform integration make use of the application name, too.
      #
      # If not set, the application name defaults to the executable name.
      def application_name
        self.class._application_name
      end

      # @return [QString]
      #
      # This property holds the version of this application.
      #
      # If not set, the application version defaults to a platform-specific
      # value determined from the main application executable or package
      # (since Qt 5.9):
      def application_version
        self.class._application_version
      end

      # @return [QString]
      #
      # Returns the directory that contains the application executable.
      #
      # For example, if you have installed Qt in the C:\Qt directory, and you
      # run the regexp example, this function will return
      # "C:/Qt/examples/tools/regexp".
      #
      # On macOS and iOS this will point to the directory actually containing
      # the executable, which may be inside an application bundle (if the
      # application is bundled).
      def application_dir_path
        self.class._application_dir_path
      end

      # @return [QString]
      #
      # Returns the file path of the application executable.
      #
      # For example, if you have installed Qt in the /usr/local/qt directory,
      # and you run the regexp example, this function will return
      # "/usr/local/qt/examples/tools/regexp/regexp".
      def application_file_path
        self.class._application_file_path
      end

      # @return [Integer]
      #
      # Returns the current process ID for the application.
      def application_pid
        self.class._application_pid
      end

      # @return [QString]
      #
      # This property holds the Internet domain of the organization that wrote
      # this application.
      #
      # The value is used by the QSettings class when it is constructed using
      # the default constructor. This saves having to repeat this information
      # each time a QSettings object is created.
      #
      # On Mac, QSettings uses organizationDomain() as the organization if
      # it's not an empty string; otherwise it uses organizationName(). On all
      # other platforms, QSettings uses organizationName() as the organization.
      def organization_domain
        self.class._organization_domain
      end

      # @return [QString]
      #
      # This property holds the name of the organization that wrote this
      # application.
      #
      # The value is used by the QSettings class when it is constructed using
      # the default constructor. This saves having to repeat this information
      # each time a QSettings object is created.
      #
      # On Mac, QSettings uses organizationDomain() as the organization if
      # it's not an empty string; otherwise it uses organizationName(). On all
      # other platforms, QSettings uses organizationName() as the organization.
      def organization_name
        self.class._organization_name
      end

      # @return [Boolean]
      #
      # This property holds whether the use of the QEventLoopLocker feature
      # can cause the application to quit.
      #
      # When this property is true the release of the last remaining
      # QEventLoopLocker operating on the application will attempt to quit the
      # application.
      #
      # Note that attempting a quit may not necessarily result in the
      # application quitting, for example if there still are open windows, or
      # the QEvent::Quit event is ignored.
      #
      # The default is true.
      def quit_lock_enabled?
        self.class._quit_lock_enabled?
      end

      # @param name [QString]
      # @return [nil]
      #
      # Sets the application's name.
      def set_application_name(name)
        self.class._set_application_name(QString.new(name))
      end

      # @param version [QString]
      # @return [nil]
      #
      # Sets the application's version.
      def set_application_version(version)
        self.class._set_application_version(QString.new(version))
      end

      # @param domain [QString]
      # @return [nil]
      #
      # Sets the application's organizationDomain property.
      def set_organization_domain(domain)
        self.class._set_organization_domain(QString.new(domain))
      end

      # @param name [QString]
      # @return [nil]
      #
      # Sets the application's organizationName property.
      def set_organization_name(name)
        self.class._set_organization_name(QString.new(name))
      end

      # @param enabled [Boolean]
      # @return [nil]
      #
      # Sets the application's quitLockEnabled property.
      def set_quit_lock_enabled(enabled)
        self.class._set_quit_lock_enabled(enabled)
      end

      # @param retcode [Integer]
      # @return [nil]
      #
      # Tells the application to exit with a return code.
      #
      # After this function has been called, the application leaves the main
      # event loop and returns from the call to exec(). The exec() function
      # returns returnCode. If the event loop is not running, this function
      # does nothing.
      #
      # By convention, a returnCode of 0 means success, and any non-zero value
      # indicates an error.
      #
      # It's good practice to always connect signals to this slot using a
      # QueuedConnection. If a signal connected (non-queued) to this slot is
      # emitted before control enters the main event loop (such as before
      # "int main" calls exec()), the slot has no effect and the application
      # never exits. Using a queued connection ensures that the slot will not
      # be invoked until after control enters the main event loop.
      #
      # Note that unlike the C library function of the same name, this
      # function does return to the caller – it is event processing that stops.
      #
      # Note also that this function is not thread-safe. It should be called
      # only from the main thread (the thread that the QCoreApplication object
      # is processing events on). To ask the application to exit from another
      # thread, either use QCoreApplication::quit() or instead call this
      # function from the main thread with QMetaMethod::invokeMethod().
      def exit(retcode = 0)
        self.class._exit(retcode)
      end

      # @return [nil]
      #
      # Asks the application to quit.
      #
      # The request may be ignored if the application prevents the quit, for
      # example if one of its windows can't be closed. The application can
      # affect this by handling the QEvent::Quit event on the application
      # level, or QEvent::Close events for the individual windows.
      #
      # If the quit is not interrupted the application will exit with return
      # code 0 (success).
      #
      # To exit the application without a chance of being interrupted, call
      # exit() directly. Note that method is not thread-safe.
      #
      # It's good practice to always connect signals to this slot using a
      # QueuedConnection. If a signal connected (non-queued) to this slot is
      # emitted before control enters the main event loop (such as before
      # "int main" calls exec()), the slot has no effect and the application
      # never exits. Using a queued connection ensures that the slot will not
      # be invoked until after control enters the main event loop.
      def quit
        self.class._quit
      end

      # @return [Integer]
      #
      # Enters the main event loop and waits until exit() is called. Returns
      # the value that was passed to exit() (which is 0 if exit() is called
      # via quit()).
      #
      # It is necessary to call this function to start event handling. The
      # main event loop receives events from the window system and dispatches
      # these to the application widgets.
      #
      # To make your application perform idle processing (by executing a
      # special function whenever there are no pending events), use a
      # QChronoTimer with 0ns timeout. More advanced idle processing schemes
      # can be achieved using processEvents().
      #
      # We recommend that you connect clean-up code to the aboutToQuit()
      # signal, instead of putting it in your application's main() function
      # because on some platforms the exec() call may not return. For example,
      # on Windows when the user logs off, the system terminates the process
      # after Qt closes all top-level windows. Hence, there is no guarantee
      # that the application will have time to exit its event loop and execute
      # code at the end of the main() function after the exec() call.
      def exec
        self.class._exec
      end

      # @param filter [QAbstractNativeEventFilter]
      # @return [nil]
      #
      # Installs an event filter filterObj for all native events received by
      # the application in the main thread.
      #
      # The event filter filterObj receives events via its nativeEventFilter()
      # function, which is called for all native events received in the main
      # thread.
      #
      # The QAbstractNativeEventFilter::nativeEventFilter() function should
      # return true if the event should be filtered, i.e. stopped. It should
      # return false to allow normal Qt processing to continue: the native
      # event can then be translated into a QEvent and handled by the
      # standard Qt event filtering, e.g. QObject::installEventFilter().
      #
      # If multiple event filters are installed, the filter that was
      # installed last is activated first.
      def install_native_event_filter(filter)
        _install_native_event_filter(filter)
      end

      # @param filter [QAbstractNativeEventFilter]
      # @return [nil]
      #
      # Removes an event filterObject from this object. The request is ignored
      # if such an event filter has not been installed.
      #
      # All event filters for this object are automatically removed when this
      # object is destroyed.
      #
      # It is always safe to remove an event filter, even during event filter
      # activation (i.e. from the nativeEventFilter() function).
      def remove_native_event_filter(filter)
        _remove_native_event_filter(filter)
      end

      # @param receiver [QObject]
      # @param event [QEvent]
      # @return [Boolean]
      #
      # Sends event to receiver: receiver->event(event). Returns the value
      # that is returned from the receiver's event handler. Note that this
      # function is called for all events sent to any object in any thread.
      #
      # For certain types of events (e.g. mouse and key events), the event
      # will be propagated to the receiver's parent and so on up to the
      # top-level object if the receiver is not interested in the event
      # (i.e., it returns false).
      #
      # There are five different ways that events can be processed;
      # reimplementing this virtual function is just one of them. All five
      # approaches are listed below:
      #
      # 1. Reimplementing paintEvent(), mousePressEvent() and so on. This is
      #    the most common, easiest, and least powerful way.
      # 2. Reimplementing this function. This is very powerful, providing
      #    complete control; but only one subclass can be active at a time.
      # 3. Installing an event filter on QCoreApplication::instance(). Such
      #    an event filter is able to process all events for all widgets, so
      #    it's just as powerful as reimplementing notify(); furthermore, it's
      #    possible to have more than one application-global event filter.
      #    Global event filters even see mouse events for disabled widgets.
      #    Note that application event filters are only called for objects
      #    that live in the main thread.
      # 4. Reimplementing QObject::event() (as QWidget does). If you do this
      #    you get Tab key presses, and you get to see the events before any
      #    widget-specific event filters.
      # 5. Installing an event filter on the object. Such an event filter
      #    gets all the events, including Tab and Shift+Tab key press events,
      #    as long as they do not change the focus widget.
      def notify(receiver, event)
        _notify(receiver, event)
      end

      private

      # rubocop:disable Style/GlobalVars
      def _initialize_qApp
        $qApp = self
      end
      # rubocop:enable Style/GlobalVars
    end
  end
end
