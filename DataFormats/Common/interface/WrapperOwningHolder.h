#ifndef DataFormats_Common_WrapperOwningHolder_h
#define DataFormats_Common_WrapperOwningHolder_h

/*----------------------------------------------------------------------

----------------------------------------------------------------------*/

#include "DataFormats/Common/interface/WrapperHolder.h"

#include <memory>
#include "FWCore/Utilities/interface/HideStdSharedPtrFromRoot.h"

namespace edm {
  class WrapperOwningHolder : private WrapperHolder {
  public:
    struct EDProductDeleter {
      explicit EDProductDeleter(WrapperInterfaceBase const* interface);
      void operator()(void const* wrapper) const;
      WrapperInterfaceBase const* interface_;
    };

    WrapperOwningHolder();

    WrapperOwningHolder(void const* wrapper, WrapperInterfaceBase const* interface);

    WrapperOwningHolder(std::shared_ptr<void const> wrapper, WrapperInterfaceBase const* interface);

    std::shared_ptr<void const> makeWrapper(void const* wrapper, WrapperInterfaceBase const* interface);

    using WrapperHolder::dynamicTypeInfo;
    using WrapperHolder::fillPtrVector;
    using WrapperHolder::fillView;
    using WrapperHolder::hasIsProductEqual;
    using WrapperHolder::interface;
    using WrapperHolder::isMergeable;
    using WrapperHolder::isPresent;
    using WrapperHolder::isProductEqual;
    using WrapperHolder::isValid;
    using WrapperHolder::mergeProduct;
    using WrapperHolder::setPtr;
    using WrapperHolder::wrappedTypeInfo;
    using WrapperHolder::wrapper;

    std::shared_ptr<void const> product() const {
      return wrapperOwner_;
    }

    void reset() {
      WrapperHolder::reset();
      wrapperOwner_.reset();
    }

  private:  
    std::shared_ptr<void const> wrapperOwner_;
  };

}
#endif
