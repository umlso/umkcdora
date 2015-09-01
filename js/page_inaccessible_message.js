(function ($) {
  Drupal.behaviors.umkcdora_append_inaccessible_message = {
    attach: function (context, settings) {
      window.IslandoraBookReader.prototype.drawLeafs = function() {
        // In the case where images could not be loaded, append an error message.
        if (1 == this.mode) {
          this.drawLeafsOnePage();
        } else if (3 == this.mode) {
          this.drawLeafsThumbnail();
        } else {
          this.drawLeafsTwoPage();
        }
        var br_images = $('img.BRnoselect');
        for (var i = 0; i < br_images.length; i++) {
          var image = br_images[i];
          $(image).on('error', function() {
            if ( !$("#data-umkcdora-copyright-restricted").length ) {
              $("#book-viewer").prepend('<div id="data-umkcdora-copyright-restricted" class="messages error">This material is restricted due to copyright and is unavailable for viewing online. If you would like a copy for personal research and study, please visit <a href="http://library.umkc.edu/spec-col-about/services">http://library.umkc.edu/spec-col-about/services</a>.</div>');
            }
          });
        }
      }
    }
  }
})(jQuery);
