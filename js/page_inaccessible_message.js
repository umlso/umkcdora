(function ($) {
  Drupal.behaviors.umkcdora_append_inaccessible_message = {
    attach: function (context, settings) {
      // Attach error event handlers to all new img.BRnoselect elements, right
      // up until the point an error event is fired from one of them.
      window.IslandoraBookReader.prototype.drawLeafs = function() {
        // Standard drawLeafs functionality.
        if (1 == this.mode) {
          this.drawLeafsOnePage();
        } else if (3 == this.mode) {
          this.drawLeafsThumbnail();
        } else {
          this.drawLeafsTwoPage();
        }
        // Attach error handlers to the new images.
        if ( !$("#data-umkcdora-copyright-restricted").length ) {
          $('img.BRnoselect').one('error', function() {
            if ( !$("#data-umkcdora-copyright-restricted").length ) {
              $("#book-viewer").prepend('<div id="data-umkcdora-copyright-restricted" class="messages error">This material is restricted due to copyright and is unavailable for viewing online. If you would like a copy for personal research and study, please visit <a href="http://library.umkc.edu/spec-col-about/services">http://library.umkc.edu/spec-col-about/services</a>.</div>');
            }
          });
        }
      }
    }
  }
})(jQuery);
