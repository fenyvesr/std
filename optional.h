  /// @brief  Primitive mock of std::optional consisting of a boolean to indicate if operation successful + payload.
  /// @note   Member mHasValue is defaulted to false, indicating the value is not initialised.
  /// @tparam T - type of the value contained in the Optional class.
  template<typename T>
  class Optional final
  {
  public:
      /// @brief     Default constructor.
      /// @param     None
      /// @pre       None
      /// @globals
      ///   None
      /// @traceability
      ///   @impl{SWD_SI_Optional_Optional_v1}
      constexpr Optional() noexcept : mHasValue(false) {}

      /// @brief        Copy constructor.
      /// @param[in]    other - other Optional instance.
      /// @pre          None
      /// @globals
      ///   [out] mHasValue \n
      ///   [out] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_Optional_v1}
      constexpr Optional(Optional const& other) noexcept(std::is_nothrow_copy_constructible<T>::value)
      : mHasValue(other.mHasValue), mValue(other.mValue) {}

      /// @brief        Move constructor deleted.
      /// @param[in]    other - other Optional instance.
      /// @pre          None
      /// @globals
      ///   [out] mHasValue \n
      ///   [out] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_Optional_v1}
      constexpr Optional(Optional&& other) noexcept(std::is_nothrow_move_constructible<T>::value)
      : mHasValue(other.mHasValue), mValue (std::move(other.mValue)) {}

      /// @brief        Parameterized copy constructor.
      /// @param[in]    val - inital value for Optional::mValue.
      /// @pre          None
      /// @globals
      ///   [out] mHasValue \n
      ///   [out] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_Optional_v1}
      constexpr Optional(T const& val) noexcept(std::is_nothrow_copy_constructible<T>::value)
      : mHasValue(true), mValue(val) {}

      /// @brief        Parameterized move constructor.
      /// @param[in]    val - inital value for Optional::mValue.
      /// @pre          None
      /// @globals
      ///   [out] mHasValue \n
      ///   [out] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_Optional_v1}
      constexpr Optional(T&& val) noexcept(std::is_nothrow_move_constructible<T>::value)
      : mHasValue(true), mValue(std::move(val)) {}

      /// @brief        Copy assignment operator.
      /// @param[in]    other - other Optional instance.
      /// @pre          None
      /// @globals
      ///   [out] mHasValue \n
      ///   [out] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_operatorAssign_v1}
      Optional& operator=(Optional const& other) noexcept(std::is_nothrow_copy_assignable<T>::value)
      { mHasValue = other.mHasValue; if(mHasValue) mValue = other.mValue; return *this; }

      /// @brief        Move assignment operator.
      /// @param[in]    other - other Optional instance.
      /// @pre          None
      /// @globals
      ///   [out] mHasValue \n
      ///   [out] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_operatorAssign_v1}
      Optional& operator=(Optional&& other) noexcept(std::is_nothrow_move_assignable<T>::value)
      { mHasValue = other.mHasValue; if(mHasValue) mValue = std::move(other.mValue); return *this; }

      /// @brief        Parameterized copy assignment operator.
      /// @param[in]    val - inital value for Optional::mValue.
      /// @pre          None
      /// @globals
      ///   [out] mHasValue \n
      ///   [out] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_operatorAssign_v1}
      Optional& operator=(T const& val) noexcept(std::is_nothrow_copy_assignable<T>::value)
      { mValue = val; mHasValue = true; return *this; }

      /// @brief        Parameterized move assignment operator.
      /// @param[in]    val - inital value for Optional::mValue.
      /// @pre          None
      /// @globals
      ///   [out] mHasValue \n
      ///   [out] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_operatorAssign_v1}
      Optional& operator=(T&& val) noexcept(std::is_nothrow_move_assignable<T>::value)
      { mValue = std::move(val); mHasValue = true; return *this; }

      /// @brief        Dereference operator.
      /// @param        None
      /// @pre          mHasValue shall be true.
      /// @globals
      ///   [out] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_operatorDereference_v1}
      T& operator*() & noexcept{ return mValue; }

      /// @brief        Const dereference operator.
      /// @param        None
      /// @pre          mHasValue shall be true.
      /// @globals
      ///   [in] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_operatorDereference_v1}
      constexpr const T& operator*() const& noexcept { return mValue; }

      /// @brief        Dereference operator.
      /// @param        None
      /// @pre          mHasValue shall be true.
      /// @globals
      ///   [in] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_operatorDereference_v1}
      T* operator->() noexcept{ return &mValue; }

      /// @brief        Const dereference operator.
      /// @param        None
      /// @pre          mHasValue shall be true.
      /// @globals
      ///   [in] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_operatorDereference_v1}
      constexpr const T* operator->() const noexcept{ return &mValue; }

      /// @brief        Explicit bool cast operator.
      /// @param        None
      /// @pre          mHasValue shall be true.
      /// @globals
      ///   [in] mHasValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_operatorBoolCast_v1}
      //constexpr explicit operator bool() const noexcept { return mHasValue; }

      /// @brief        Getter for mHasValue.
      /// @param        None
      /// @pre          None
      /// @globals
      ///   [in] mHasValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_operatorBoolCast_v1}
      constexpr bool hasValue() const noexcept { return mHasValue; }

      /// @brief        Reset the object.
      /// @param        None
      /// @pre          None
      /// @globals
      ///   [in, out] mHasValue \n
      ///   [out] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_reset_v1}
      void reset() noexcept(std::is_destructible<T>::value) { mValue.~T(); mHasValue = false; }

      /// @brief        Getter for mValue.
      /// @param        None
      /// @pre          None
      /// @globals
      ///   [in] mHasValue \n
      ///   [in] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_value_v1}
      T& value() & noexcept
      {
          if (!mHasValue)
          {
              reportMessage(SmartCharArray::getReportMessage() + "Optional::value() was called with undefined mValue!", SI_REPORT_LEVEL::CRITICAL, SI_REPORT_COMPONENT::SI_CORE_HELPER);
          }
          return mValue;
      }

      /// @brief        Const getter for mValue.
      /// @param        None
      /// @pre          None
      /// @globals
      ///   [in] mHasValue \n
      ///   [in] mValue
      /// @traceability
      ///   @impl{SWD_SI_Optional_value_v1}
      const T& value() const & noexcept
      {
          if (!mHasValue)
          {
              reportMessage(SmartCharArray::getReportMessage() + "Optional::value() was called with undefined mValue!", SI_REPORT_LEVEL::CRITICAL, SI_REPORT_COMPONENT::SI_CORE_HELPER);
          }
          return mValue;
      }

  private:
      /// @brief If true, mValue is valid and can be used.
      ///        Setting the default value to true shall be avoided, since the mValue might not be available yet.
      bool mHasValue{ false };
      /// @brief Braces necessary to ensure initialization of mValue when T is non-POD type.
      T    mValue{};
  };
